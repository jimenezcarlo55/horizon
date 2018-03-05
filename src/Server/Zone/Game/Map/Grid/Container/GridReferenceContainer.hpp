
#ifndef HORIZON_CORE_STRUCTURES_GRIDREFERENCECONTAINER_HPP
#define HORIZON_CORE_STRUCTURES_GRIDREFERENCECONTAINER_HPP

#include "Core/Structures/TypeList.hpp"
#include "Server/Zone/Game/Map/Grid/GridRefManager.hpp"

/*============================*
 * Container Data Type
 *============================*/
template<class OBJECT>
struct GridTypeListContainer
{
	GridRefManager<OBJECT> _element;
};

template<>
struct GridTypeListContainer<TypeNull>
{
};

template<class HEAD, class TAIL>
struct GridTypeListContainer<TypeList<HEAD, TAIL>>
{
	GridTypeListContainer<HEAD> _elements;
	GridTypeListContainer<TAIL> _tail_elements;
};

/*============================*
 * TypeListIterator Insert Functions
 *============================*/
// non-const insert functions
namespace GridTypeListIterator
{
	template<class SPECIFIC_TYPE>
	SPECIFIC_TYPE *Insert(GridTypeListContainer<SPECIFIC_TYPE> &elements, SPECIFIC_TYPE *obj)
	{
		obj->addReference(elements._element);
		return obj;
	}
	template<class SPECIFIC_TYPE>
	SPECIFIC_TYPE *Insert(GridTypeListContainer<TypeNull> &/*elements*/, SPECIFIC_TYPE */*obj*/)
	{
		return nullptr;
	}
	// this is a missed
	template<class SPECIFIC_TYPE, class T>
	SPECIFIC_TYPE *Insert(GridTypeListContainer<T> &/*elements*/, SPECIFIC_TYPE */*obj*/)
	{
		return nullptr;                                        // a missed
	}
	// Recursion
	template<class SPECIFIC_TYPE, class HEAD, class TAIL>
	SPECIFIC_TYPE* Insert(GridTypeListContainer<TypeList<HEAD, TAIL>> &elements, SPECIFIC_TYPE* obj)
	{
		SPECIFIC_TYPE *t = Insert(elements._elements, obj);
		return (t != nullptr ? t : Insert(elements._tail_elements, obj));
	}
	/*============================*
	 * TypeListIterator Count Functions
	 *============================*/
	// count functions
	template <class SPECIFIC_TYPE>
	size_t count(GridTypeListContainer<SPECIFIC_TYPE> const &elements, SPECIFIC_TYPE */*fake*/)
	{
		return elements._element.size();
	}
	template <class SPECIFIC_TYPE>
	size_t count(GridTypeListContainer<TypeNull> const &/*elements*/, SPECIFIC_TYPE */*fake*/)
	{
		return 0;
	}
	template <class SPECIFIC_TYPE, class T>
	size_t count(GridTypeListContainer<T> const &/*elements*/, SPECIFIC_TYPE */*fake*/)
	{
		return 0;
	}
	template <class SPECIFIC_TYPE, class T>
	size_t count(GridTypeListContainer<TypeList<SPECIFIC_TYPE, T>> const &elements, SPECIFIC_TYPE *fake)
	{
		return count(elements._elements, fake);
	}
	template <class SPECIFIC_TYPE, class H, class T>
	size_t count(GridTypeListContainer<TypeList<H, T>> const &elements, SPECIFIC_TYPE *fake)
	{
		return count(elements._tail_elements, fake);
	}
}
/*============================*
 * GridReferenceContainer
 *============================*/
template<class OBJECT_TYPES>
class GridReferenceContainer
{
public:
	template <class SPECIFIC_TYPE>
	size_t count() const
	{
		return GridTypeListIterator::count(_elements, (SPECIFIC_TYPE *) NULL);
	}

	/// inserts a specific object into the container
	template <class SPECIFIC_TYPE>
	bool insert(SPECIFIC_TYPE *obj)
	{
		assert(!obj->valid());
		SPECIFIC_TYPE* t = GridTypeListIterator::Insert(_elements, obj);
		return (t != NULL);
	}

	GridTypeListContainer<OBJECT_TYPES> &getElements(void) { return _elements; }
	const GridTypeListContainer<OBJECT_TYPES> &getElements(void) const { return _elements;}

private:
	GridTypeListContainer<OBJECT_TYPES> _elements;
};

#endif /* HORIZON_CORE_STRUCTURES_GRIDREFERENCECONTAINER_HPP */