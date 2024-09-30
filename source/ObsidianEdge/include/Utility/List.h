#ifndef GLOBAL_LIST_H
#define GLOBAL_LIST_H

template <typename T, typename S = int>
class Node
{
public:
    Node()
        : m_prev(nullptr), m_next(nullptr)
    {
    }

    Node(T val, Node<T, S> *prev = nullptr, Node<T, S> *next = nullptr)
        : m_prev(prev), m_next(next), m_val(val)
    {
    }

    Node *Prev() const
    {
        return m_prev;
    }

    Node *Next() const
    {
        return m_next;
    }

    void SetPrev(Node<T, S> *prev)
    {
        m_prev = prev;
    }

    void SetNext(Node<T, S> *next)
    {
        m_next = next;
    }

    T Val() const
    {
        return m_val;
    }

    void SetVal(T val)
    {
        m_val = val;
    }

    void Set(T val, Node<T, S> *prev = nullptr, Node<T, S> *next = nullptr)
    {
        SetPrev(prev);
        SetNext(next);
        SetVal(val);
    }

private:
    Node<T, S> *m_prev = nullptr;
    Node<T, S> *m_next = nullptr;

    T m_val;
};

/**
 * @brief A multi-purposes, dynamic list data structure.
 *
 * @tparam T Class to contain.
 * @tparam S Size for indexing, if unsigned, will not work.
 */
template <typename T, typename S = int>
class List
{
public:
    List()
        : m_first(nullptr), m_last(nullptr), m_size(0)
    {
    }

    List(const T *arr, const S size)
    {
        for (S i = 0; i < size; i++)
            Append(new Node<T, S>(arr[i]));
    }

    ~List()
    {
        while (m_size)
            DeleteFirst();
    }

    List(const List<T, S> &other)
    {
        *this = other;
    }

    List(List<T, S> &&other) noexcept
    {
        *this = std::move(other);
    }

    List<T, S> &operator=(const List<T, S> &other)
    {
        for (S i = 0; i < other.m_size; i++)
        {
            Append(other[i].Val());
        }

        return *this;
    }

    List<T, S> &operator=(List<T, S> &&other) noexcept
    {
        m_first = other.m_first;
        m_last = other.m_last;

        other.m_first = nullptr;
        other.m_last = nullptr;

        m_size = other.m_size;
        other.m_size = 0;

        return *this;
    }

    Node<T, S> *operator[](S index)
    {
        Node<T, S> *current = index < 0 ? m_last : m_first;

        if (index >= m_size || index < -m_size)
        {
            return nullptr;
        }

        while (index != 0 && index != -1)
        {
            if (index < 0)
            {
                current = current->Prev();
                index += 1;
            }
            else
            {
                current = current->Next();
                index -= 1;
            }
        }

        return current;
    }

    void Prepend(Node<T, S> *node)
    {
        if (node == nullptr)
        {
            return;
        }

        if (m_size == 0)
        {
            m_first = node;
            m_last = node;

            m_size = 1;

            return;
        }

        m_first->setPrev(node);
        node->SetNext(m_first);
        m_first = node;

        m_size += 1;
    }

    void Append(Node<T, S> *node)
    {
        if (node == nullptr)
        {
            return;
        }

        if (m_size == 0)
        {
            m_first = node;
            m_last = node;

            m_size = 1;

            return;
        }

        m_last->SetNext(node);
        node->SetPrev(m_last);
        m_last = node;

        m_size += 1;
    }

    /// @brief Remove and delete the first element.
    void DeleteFirst()
    {
        if (m_size == 0)
        {
            return;
        }

        if (m_size == 1)
        {
            Node<T, S> *node = m_first;

            m_first = nullptr;
            m_last = nullptr;

            delete node;
            m_size = 0;

            return;
        }

        Node<T, S> *node = m_first;

        m_first = m_first->Next();
        m_first->SetPrev(nullptr);
        delete node;

        m_size -= 1;
    }

    /// @brief Remove and delete the last element.
    void DeleteLast()
    {
        if (m_size == 0)
        {
            return;
        }

        if (m_size == 1)
        {
            Node<T, S> *node = m_last;

            m_first = nullptr;
            m_last = nullptr;

            delete node;
            m_size = 0;

            return;
        }

        Node<T, S> *node = m_last;

        m_last = m_last->Prev();
        m_last->SetNext(nullptr);
        delete node;

        m_size -= 1;
    }

    void Clear()
    {
        while (m_size)
            DeleteFirst();
    }

private:
    Node<T, S> *m_first = nullptr;
    Node<T, S> *m_last = nullptr;

    S m_size = 0;
};

#endif
