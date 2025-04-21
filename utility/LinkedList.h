#ifndef OE_LINKEDLIST1_H
#define OE_LINKEDLIST1_H

#include "Utility/Container.h"

#include <limits.h>

namespace ObsidianEdge
{
    /**
     * 2-Way Linked List
     */
    template <typename T>
    class LinkedList : public Container<T>
    {
    public:
        LinkedList()
            : m_head(nullptr), m_tail(nullptr), m_size(0) {}

        template <typename... Args>
        LinkedList(Args... args)
            : m_head(nullptr), m_tail(nullptr), m_size(0)
        {
            initializer(args...);
        }

        template <typename... Args>
        void initializer(T value, Args... args)
        {
            append(value);

            if constexpr (sizeof...(args) > 0)
                initializer(args...);
        }

        LinkedList(const LinkedList &other)
        {
            *this = other;
        }

        LinkedList(LinkedList &&other) noexcept
        {
            *this = std::move(other);
        }

        /**
         * @brief Return Node object reference at index
         */
        Node<T> &operator[](long long index) const
        {
            if (index >= m_size || index < -((long long)m_size))
            {
                throw std::runtime_error("Invalid Index");
            }

            if (index >= 0)
            {
                if (index > ((long long)m_size) / 2)
                {
                    index = -(m_size - index);
                }
            }
            else
            {
                if (index < -((long long)m_size) / 2)
                {
                    index = index + m_size;
                }
            }

            Node<T> *cur = (index >= 0 ? m_head : m_tail);

            while (index != -1 && index != 0)
            {
                if (index > 0)
                {
                    cur = cur->next();
                    index -= 1;
                }
                else
                {
                    cur = cur->prev();
                    index += 1;
                }
            }

            return *cur;
        }

        /**
         * @brief Return pointer of Node object at index
         */
        Node<T> *get(long long index)
        {
            if (index >= m_size || index < -((long long)m_size))
            {
                throw std::runtime_error("Invalid Index");
            }

            if (index >= 0)
            {
                if (index > ((long long)m_size) / 2)
                {
                    index = -(m_size - index);
                }
            }
            else
            {
                if (index < -((long long)m_size) / 2)
                {
                    index = index + m_size;
                }
            }

            Node<T> *cur = (index >= 0 ? m_head : m_tail);

            while (index != -1 && index != 0)
            {
                if (index > 0)
                {
                    cur = cur->next();
                    index -= 1;
                }
                else
                {
                    cur = cur->prev();
                    index += 1;
                }
            }

            return cur;
        }

        void remove(long long index)
        {
            if (index == 0 || index == -((long long)m_size))
            {
                m_head = m_head->next();
                delete m_head->prev();

                m_head->setPrev(nullptr);

                return;
            }

            if (index == -1 || index == (m_size - 1))
            {
                m_tail = m_tail->prev();
                delete m_tail->next();

                m_head->setNext(nullptr);

                return;
            }

            Node<T> *cur = get(index);

            cur->prev()->setNext(cur->next());
            cur->next()->setPrev(cur->prev());

            delete cur;
            m_size--;
        }

        LinkedList &operator=(const LinkedList &other)
        {
            if (other.m_size == 0)
            {
                clear();
                return *this;
            }

            if (m_size)
            {
                clear();
            }

            Node<T> *next = other.m_head->next();
            Node<T> *curr = new Node<T>((T)other.m_head);

            m_head = curr;
            m_size = 1;

            while (next)
            {
                Node<T> *temp = new Node<T>((T)next);

                curr->setNext(temp);
                temp->setPrev(curr);

                next = next->next();
                curr = temp;

                m_size++;
            }

            m_tail = curr;

            return *this;
        }

        LinkedList &operator=(LinkedList &&other) noexcept
        {
            if (other.m_size == 0)
            {
                clear();
                return *this;
            }

            if (m_size)
            {
                clear();
            }

            m_head = other.m_head;
            m_tail = other.m_tail;
            m_size = other.m_size;

            other.m_head = nullptr;
            other.m_tail = nullptr;
            other.m_size = 0;

            return *this;
        }

        Node<T> &front() const override
        {
            return head();
        }

        Node<T> &back() const override
        {
            return back();
        }

        Node<T> &head() const
        {
            return *m_head;
        }

        Node<T> &tail() const
        {
            return *m_tail;
        }

        unsigned int size() const override
        {
            return m_size;
        }

        void addFront(const T &other) override
        {
            prepend(other);
        }

        void addBack(const T &other) override
        {
            append(other);
        }

        LinkedList &prepend(const T &other)
        {
            if (m_size >= UINT_MAX)
            {
                throw std::runtime_error("Linked List Capacity Exceeded!");
            }

            Node<T> *temp = new Node<T>(other);

            if (m_size)
            {
                temp->setNext(m_head);
                m_head->setPrev(temp);

                m_head = temp;
            }
            else
            {
                m_head = temp;
                m_tail = temp;
            }

            m_size++;

            return *this;
        }

        LinkedList &append(const T &other)
        {
            if (m_size >= UINT_MAX)
            {
                throw std::runtime_error("Linked List Capacity Exceeded!");
            }

            Node<T> *temp = new Node<T>(other);

            if (m_size)
            {
                temp->setPrev(m_tail);
                m_tail->setNext(temp);

                m_tail = temp;
            }
            else
            {
                m_head = temp;
                m_tail = temp;
            }

            m_size++;

            return *this;
        }

        void popFront() override
        {
            popHead();
        }

        void popBack() override
        {
            popTail();
        }

        LinkedList &popHead()
        {
            if (m_head == nullptr)
                return *this;

            Node<T> *temp = m_head;
            m_head = m_head->next();

            delete temp;
            m_head->setPrev(nullptr);

            m_size--;

            return *this;
        }

        LinkedList &popTail()
        {
            if (m_tail == nullptr)
                return *this;

            Node<T> *temp = m_tail;
            m_tail = m_tail->prev();

            delete temp;
            m_tail->setNext(nullptr);

            m_size--;

            return *this;
        }

        LinkedList &clear()
        {
            while (m_size)
                popTail();

            return *this;
        }

    private:
        Node<T> *m_head = nullptr;
        Node<T> *m_tail = nullptr;
        unsigned int m_size = 0; // 16 bits size helper [0, 4294967295]
    };

    template <typename T>
    class LinkedListIterator
    {
    public:
    private:
        LinkedList<T> m_host = nullptr;
        Node<T>* m_cur = nullptr;
    };
}

#endif