//Phillip Levin

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Mlist
{
	public:
	Mlist();//creates the list
	T front();//returns the front of the list
	T end();//returns the end of the list and moves every entry up one position;
	bool in(T x);//returns true if x is in the list and false otherwise
	bool empty(); // returns true if the list is empty
	void addfront(T entry);//add entry to the back of the list
	void addend(T entry);//add entry to the back of the list
	void addorder(T entry);//add entry to an ordered list
	void removefront();//removes the front of the list
	void removeend();//removes the back of the list
	void remove(T n);//searches the list and removes the entry with value n
	
	private:
	vector<T> mlist;
	void remove(typename vector<T>::iterator ix, T n);//uses an iterator and recursion to remove value n
	void addorder(typename vector<T>::iterator ix, T n);//uses an iterator and recursion to add value n in an ordered list
		
}; 

// Mlist

template<typename T>
Mlist<T>::Mlist()
{

}

template<typename T>
T Mlist<T>:: front()
{
	return mlist[0];
}

template<typename T>
T Mlist<T>:: end()
{
	return mlist[mlist.size()-1];
} 

template<typename T>
bool Mlist<T>:: in(T x)
{
	for (int i = 0; i < mlist.size(); ++i)
	{
		if (mlist[i] == x)
		{
			return true;
		}
	}
	
	return false;
}

template<typename T>
bool Mlist<T>:: empty()
{
 	if(mlist.size() == 0)
 	{
 		return true;
 	}
 	else return false;
}

template<typename T>
void Mlist<T>:: addfront(T entry)
{
	mlist.insert(mlist.begin(), entry);
}

template<typename T>
void Mlist<T>:: addend(T entry)
{
	mlist.insert(mlist.end(), entry);
}

template<typename T>
void Mlist<T>::addorder(T entry)
{
	
	if (mlist.size() > 0)
	{
		addorder(mlist.begin(), entry);
	}
	else
		mlist.insert(mlist.begin(), entry);
	
}

template<typename T>
void Mlist<T>::addorder(typename vector<T>::iterator ix, T n)
{
	
	if(ix == mlist.end())
	{
		mlist.insert(mlist.end(), n);
	}
	else
	{
		if(n <= *ix)
		{
			mlist.insert(ix, n);
		}
		
		else
		{
			addorder(++ix, n);
		}
	}
}

template<typename T>
void Mlist<T>:: removefront()
{
	mlist.erase(mlist.begin());
}

template<typename T>
void Mlist<T>:: removeend()
{
	mlist.erase(--mlist.end());

}

template<typename T>
void Mlist<T>:: remove(T n)
{
	
	if(mlist.size() > 0)
	{
		remove(mlist.begin(), n);
	}
	
}

template<typename T>
void Mlist<T>:: remove(typename vector<T>::iterator ix, T n)
{
	if (ix == mlist.end())
	{
		return;
	}
	else
	{
		if(*ix == n)
		{
			mlist.erase(ix);
			remove(ix, n);
		}
		else
		{
			remove(++ix, n);
		}
	}
}

int main()
{
	 //Tests for using ints w/ addend
	 cout << endl;
	 Mlist<int> test1=Mlist<int>();
	 test1.addend(5);
	 test1.addend(7);
	 test1.addend(4);
	 if(test1.in(7) == true) cout << "in(7) run. 7 is in vector" << endl;
	 cout << "At the front: " << test1.front()<< endl;
	 cout << "At the back: " << test1.end()<< endl;
	 test1.remove(4);
	 cout << "remove(4) run. At the front: " << test1.front()<< endl;
	 cout << "At the back: " << test1.end()<< endl;
	 test1.remove(7);
	 test1.remove(5);
	 if(test1.empty() == true) cout << "remove(7) and remove(5) run. Vector is now empty" << endl;
	 cout << endl;
	 
	 //Tests for using strings w/ addfront
	 Mlist<string> test2= Mlist<string>();
	 test2.addfront("John");
	 test2.addfront("Paul");
	 test2.addfront("Mary");
	 test2.addfront("Kate");
	 if(test2.in("Paul") == true) cout << "in(Paul) run. Paul is in vector" << endl;
	 cout << "At the front: " << test2.front() << endl;
	 cout << "At the back: " << test2.end() << endl;
	 test2.remove("Paul");
	 cout << "remove(Paul) run. At the front: " << test2.front() << endl;
	 cout << "At the back: " << test2.end() << endl;
	 test2.remove("John");
	 cout << "remove(John) run. At the front: " << test2.front() << endl;
	 cout << "At the back: " << test2.end() << endl;
	 test2.remove("Kate");
	 test2.remove("Mary");
	 if(test2.empty() == true) cout << "remove(Kate) and remove(Marry) run. Vector is now empty" << endl;
	 cout << endl;
	 
	 //Tests for using doubles w/ addorder
	 Mlist<double> test3 = Mlist<double>();
	 test3.addorder(2.3);
	 test3.addorder(8.4);
	 test3.addorder(4.5);
	 cout << "At the front: " << test3.front() << endl;
	 cout << "At the back: " << test3.end() << endl;
	 test3.addorder(1.3);
	 test3.addorder(11.1);
	 cout << "addorder(1.3) and addorder(11.1) run. At the front: " << test3.front() << endl;
	 cout << "At the back: " << test3.end() << endl;	
	 
}
