/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _DECAF_UTIL_STLLIST_H_
#define _DECAF_UTIL_STLLIST_H_

#include <list>
#include <algorithm>
#include <memory>
#include <decaf/lang/exceptions/UnsupportedOperationException.h>
#include <decaf/lang/exceptions/NoSuchElementException.h>
#include <decaf/lang/exceptions/IndexOutOfBoundsException.h>
#include <decaf/util/concurrent/Synchronizable.h>
#include <decaf/util/concurrent/Mutex.h>
#include <decaf/util/Config.h>
#include <decaf/util/Iterator.h>
#include <decaf/util/ListIterator.h>
#include <decaf/util/List.h>

namespace decaf{
namespace util{

    /**
     * List class that wraps the STL list object to provide a simpler interface and
     * additional methods not provided by the STL type.
     */
    template <typename E>
    class StlList : public decaf::util::List<E> {
    private:

        std::list<E> values;

    private:

        class StlListIterator : public ListIterator<E> {
        private:

            typename std::list<E>::iterator current;
            typename std::list<E>::iterator prev;
            typename std::list<E>* list;

        private:

            StlListIterator( const StlListIterator& ) :
                ListIterator<E>(), current(), prev(), list( NULL ) {}
            StlListIterator operator= ( const StlListIterator& ) { return *this; }

        public:

            StlListIterator( typename std::list<E>* list, int index ) :
                current( list->begin() ), prev( list->end() ), list( list ) {

                std::advance( this->current, index );
            }

            virtual ~StlListIterator() {}

            virtual E next() {
                if( this->current == list->end() ) {
                    throw lang::exceptions::NoSuchElementException(
                        __FILE__, __LINE__,
                        "List::Iterator::next - No more elements to return" );
                }

                this->prev = this->current;
                return *( this->current++ );
            }

            virtual bool hasNext() const {
                return ( this->current != list->end() );
            }

            virtual void remove() {
                if( this->prev == list->end() ) {
                    throw lang::exceptions::IllegalStateException(
                        __FILE__, __LINE__,
                        "List::Iterator::remove - Invalid State to call remove" );
                }

                this->list->erase( this->prev );
                this->prev = this->list->end();
            }

            virtual void add( const E& e DECAF_UNUSED ) {

                throw lang::exceptions::UnsupportedOperationException(
                    __FILE__, __LINE__,
                    "List::ListIterator::add - Not Implemented Yet." );
            }

            virtual void set( const E& e ) {

                if( this->current == list->end() ) {
                    throw lang::exceptions::IllegalStateException(
                        __FILE__, __LINE__,
                        "List::Iterator::set - Not a valid state for set" );
                }

                *( this->current ) = e;
            }

            virtual bool hasPrevious() const {
                return ( this->current != this->list->begin() );
            }

            virtual E previous() {
                if( this->current == this->list->begin() ) {
                    throw lang::exceptions::NoSuchElementException(
                        __FILE__, __LINE__,
                        "List::ListIterator::previous - No Previous element." );
                }

                typename std::list<E>::const_iterator iter = this->current;
                return *( iter-- );
            }

            virtual int nextIndex() const {
                if( this->current == this->list->end() ) {
                    return (int)this->list->size();
                }

                return (int)std::distance( this->list->begin(), this->current );
            }

            virtual int previousIndex() const {
                if( this->current == this->list->begin() ) {
                    return -1;
                }

                return (int)std::distance( this->list->begin(), this->current ) - 1;
            }

        };

        class ConstStlListIterator : public decaf::util::ListIterator<E> {
        private:

            typename std::list<E>::const_iterator current;
            typename std::list<E>::const_iterator prev;
            const typename std::list<E>* list;

        private:

            ConstStlListIterator( const ConstStlListIterator& ) :
                ListIterator<E>(), current(), prev(), list( NULL ) {}
            ConstStlListIterator operator= ( const ConstStlListIterator& ) { return *this; }

        public:

            ConstStlListIterator( const typename std::list<E>* list, int index ) :
                ListIterator<E>(), current( list->begin() ), prev( list->end() ), list( list ) {

                std::advance( this->current, index );
            }

            virtual ~ConstStlListIterator() {}

            virtual E next() {
                if( this->current == list->end() ) {
                    throw lang::exceptions::NoSuchElementException(
                        __FILE__, __LINE__,
                        "List::Iterator::next - No more elements to return" );
                }

                this->prev = this->current;
                return *( this->current++ );
            }

            virtual bool hasNext() const {
                return ( this->current != list->end() );
            }

            virtual void remove() {

                throw lang::exceptions::UnsupportedOperationException(
                    __FILE__, __LINE__,
                    "List::ListIterator::remove - Const Iterator." );
            }

            virtual void add( const E& e DECAF_UNUSED ) {

                throw lang::exceptions::UnsupportedOperationException(
                    __FILE__, __LINE__,
                    "List::ListIterator::add - Const Iterator." );
            }

            virtual void set( const E& e DECAF_UNUSED ) {

                throw lang::exceptions::UnsupportedOperationException(
                    __FILE__, __LINE__,
                    "List::ListIterator::set - Const Iterator." );
            }

            virtual bool hasPrevious() const {
                return ( this->current != this->list->begin() );
            }

            virtual E previous() {
                if( this->current == this->list->begin() ) {
                    throw lang::exceptions::NoSuchElementException(
                        __FILE__, __LINE__,
                        "List::ListIterator::previous - No Previous element." );
                }

                typename std::list<E>::const_iterator iter = this->current;
                return *( iter-- );
            }

            virtual int nextIndex() const {
                if( this->current == this->list->end() ) {
                    return (int)this->list->size();
                }

                return (int)std::distance( this->list->begin(), this->current );
            }

            virtual int previousIndex() const {
                if( this->current == this->list->begin() ) {
                    return -1;
                }

                return (int)std::distance( this->list->begin(), this->current ) - 1;
            }
        };

    public:

        /**
         * Default constructor - does nothing.
         */
        StlList() : List<E>(), values() {}

        /**
         * Copy constructor - copies the content of the given set into this
         * one.
         * @param source The source set.
         */
        StlList( const StlList& source ) : List<E>(), values() {
            copy( source );
        }

        /**
         * Copy constructor - copies the content of the given set into this
         * one.
         * @param source The source set.
         */
        StlList( const Collection<E>& source ) : List<E>(), values() {
            List<E>::copy( source );
        }

        virtual ~StlList() {}

        /**
         * {@inheritDoc}
         */
        virtual bool equals( const StlList& source ) const {
            return this->values == source.values;
        }

        /**
         * {@inheritDoc}
         */
        virtual Iterator<E>* iterator() {
            return new StlListIterator( &values, 0 );
        }
        virtual Iterator<E>* iterator() const {
            return new ConstStlListIterator( &values, 0 );
        }

        /**
         * {@inheritDoc}
         */
        virtual ListIterator<E>* listIterator() {
            return new StlListIterator( &values, 0 );
        }
        virtual ListIterator<E>* listIterator() const {
            return new ConstStlListIterator( &values, 0 );
        }

        /**
         * {@inheritDoc}
         */
        virtual ListIterator<E>* listIterator( int index ) {

            if( index >= this->size() ) {
                throw decaf::lang::exceptions::IndexOutOfBoundsException(
                    __FILE__, __LINE__,
                    "List::listIterator - Index greater than size()" );
            }

            return new StlListIterator( &values, index );
        }
        virtual ListIterator<E>* listIterator( int index ) const {

            if( index >= this->size() ) {
                throw decaf::lang::exceptions::IndexOutOfBoundsException(
                    __FILE__, __LINE__,
                    "List::listIterator - Index greater than size()" );
            }

            return new ConstStlListIterator( &values, index );
        }

        /**
         * {@inheritDoc}
         */
        virtual void copy( const StlList& source ) {
            this->values.clear();
            this->values = source.values;
        }

        /**
         * {@inheritDoc}
         */
        virtual void clear() {
            values.clear();
        }

        /**
         * {@inheritDoc}
         */
        virtual bool contains( const E& value ) const {
            typename std::list<E>::const_iterator iter;
            iter = std::find( values.begin(), values.end(), value );
            return iter != values.end();
        }

        /**
         * {@inheritDoc}
         */
        virtual int indexOf( const E& value ) {

            typename std::list<E>::iterator iter;
            iter = std::find( values.begin(), values.end(), value );

            if( iter == values.end() ) {
                throw decaf::lang::exceptions::NoSuchElementException(
                    __FILE__, __LINE__,
                    "List::indexOf - No matching element in list" );
            }

            return (int)std::distance( values.begin(), iter );
        }

        /**
         * {@inheritDoc}
         */
        virtual int lastIndexOf( const E& value ) {

            typename std::list<E>::reverse_iterator iter;
            iter = std::find( values.rbegin(), values.rend(), value );

            if( iter == values.rend() ) {
                throw decaf::lang::exceptions::NoSuchElementException(
                    __FILE__, __LINE__,
                    "List::lastIndexOf - No matching element in list" );
            }

            // Now reverse the result to get the last index
            return (int)( this->size() - std::distance( values.rbegin(), iter ) - 1 );
        }

        /**
         * {@inheritDoc}
         */
        virtual bool isEmpty() const {
            return values.empty();
        }

        /**
         * {@inheritDoc}
         */
        virtual int size() const {
            return (int)values.size();
        }

        /**
         * {@inheritDoc}
         */
        virtual E get( int index ) const {

            if( index >= this->size() ) {
                throw decaf::lang::exceptions::IndexOutOfBoundsException(
                    __FILE__, __LINE__,
                    "List::get - Index greater than size()" );
            }

            // Advance from begin and return the value at that location.
            typename std::list<E>::const_iterator iter = this->values.begin();
            std::advance( iter, index );
            return *( iter );
        }

        /**
         * {@inheritDoc}
         */
        virtual E set( int index, const E& element ) {

            if( index >= this->size() ) {
                throw decaf::lang::exceptions::IndexOutOfBoundsException(
                    __FILE__, __LINE__,
                    "List::get - Index greater than size()" );
            }

            // Advance from begin and return the value at that location
            // after setting the value to the new value.
            typename std::list<E>::iterator iter = this->values.begin();
            std::advance( iter, index );
            E oldValue = *iter;
            *iter = element;

            return oldValue;
        }

        /**
         * {@inheritDoc}
         */
        virtual bool add( const E& value ) {
            values.insert( values.end(), value );
            return true;
        }

        /**
         * {@inheritDoc}
         */
        virtual void add( int index, const E& element ) {

            if( index > this->size() ) {
                throw decaf::lang::exceptions::IndexOutOfBoundsException(
                    __FILE__, __LINE__,
                    "List::add - Index greater than size()" );
            }

            // Advance from begin and insert the value at that location
            typename std::list<E>::iterator iter = this->values.begin();
            std::advance( iter, index );
            this->values.insert( iter, element );
        }

        /**
         * {@inheritDoc}
         */
        virtual bool addAll( int index, const Collection<E>& source ) {

            if( index != 0 && index > this->size() ) {
                throw decaf::lang::exceptions::IndexOutOfBoundsException(
                    __FILE__, __LINE__,
                    "List::addAll - Index greater than size()" );
            }

            std::auto_ptr< Iterator<E> > srcIter( source.iterator() );
            while( srcIter->hasNext() ) {
                this->add( index++, srcIter->next() );
            }

            return !source.isEmpty();
        }

        /**
         * {@inheritDoc}
         */
        virtual bool remove( const E& value ) {

            int origSize = this->size();
            this->values.remove( value );
            return origSize != this->size();
        }

        /**
         * {@inheritDoc}
         */
        virtual E remove( int index ) {

            if( index > this->size() ) {
                throw decaf::lang::exceptions::IndexOutOfBoundsException(
                    __FILE__, __LINE__,
                    "List::add - Index greater than size()" );
            }

            // Advance from begin and insert the value at that location
            typename std::list<E>::iterator iter = this->values.begin();
            std::advance( iter, index );
            E oldValue = *iter;
            this->values.erase( iter );

            return oldValue;
        }

    };

}}

#endif /*_DECAF_UTIL_STLLIST_H_*/
