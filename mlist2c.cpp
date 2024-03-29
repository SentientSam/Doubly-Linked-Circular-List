#include <iostream>
#include <iomanip>
#include <list2c.h>

// choose one from group A 

// =====================
// ===== group A =======
// =====================

// A1: makes lists of char
#include <xran.h>
#include <xran.cpp>  // in lieu of makefile
typedef char          ElementType;
typedef fsu::Random_letter Random_class;
const char* vT = "char";
const char a = '1';
const long unsigned int maxSize        =    20000;
const long unsigned int reportInterval =  5000000;
const      unsigned int purgePercent   =       20;    // adjust these
const      unsigned int removePercent  =      100;    // to control
const      unsigned int insertPercent  =       80;    // growth rate
const      unsigned int assignPercent  =        2;    // and
const      unsigned int appendPercent  =        2;    // volatility
// end A1 */

/* // A2: makes lists of String
#include <xstring.h>
#include <xran.h>
#include <xranxstr.h>
#include <xstring.cpp>  // in lieu of makefile
#include <xran.cpp>     // in lieu of makefile
#include <xranxstr.cpp> // in lieu of makefile
typedef fsu::String        ElementType;
typedef fsu::Random_String Random_class;
const char* vT = "String";
const char a = '2';
const long unsigned int maxSize        =    10000;
const long unsigned int reportInterval =   100000;
const      unsigned int purgePercent   =      100;    // adjust these
const      unsigned int removePercent  =      100;    // to control
const      unsigned int insertPercent  =       80;    // growth rate
const      unsigned int assignPercent  =        1;    // and
const      unsigned int appendPercent  =        1;    // volatility
// end A2 */

// constants for number of containers and operations
const unsigned int numObj = 3;  // containers x0, x1, x2
const unsigned int numOps = 26; // operations 0..25

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cout << " ** Argument required:  number of reports (enter 0 for unlimited)\n"
              << "    Try again\n";
    return 0;
  }
  size_t maxrpts = atoi(argv[1]);
  std::cout << "\nStarting dynamic random test of List < " << vT << " >"
            << "\n\n" << std::flush;

  // objects
  alt2c::List<ElementType> x0, x1, x2;
  alt2c::List<ElementType>::Iterator i0, i1, i2, iter;
  alt2c::List<ElementType> * Lptr;
  Random_class   ranobj;
  ElementType    Tval;

  // controls
  fsu::Random_int ranint;
  unsigned long numtrials(0);
  unsigned long numrpts(0); 
  unsigned int option;

  // reporting
  size_t capacity;
  while(1)
  {
    option = ranint(0,numObj);
    switch(option)
    {
      case 0: 
        option = ranint(0,numOps); 
        switch (option)
        {

          case 0:   // void Release ()
            capacity = x0.Capacity();
            if (capacity >= maxSize)
            {
              x0.Release();
              i0 = x0.Begin();
              std::cout << "x0 released at capacity " << capacity << std::endl;
            }
            break;

          case 1:   // void PushFront (t)
            option = ranint(0,100);
            if (option < insertPercent)
            {
              Tval = ranobj();
              x0.PushFront(Tval);
            }
            break;
        
          case 2:   // void PushBack (t)
            option = ranint(0,100);
            if (option < insertPercent)
            {
              Tval = ranobj();
              x0.PushBack(Tval);
            }
            break;
        
          case 3:   // void Insert (i0,t)
            option = ranint(0,100);
            if (option < insertPercent)
            {
              Tval = ranobj();
              if (i0.Valid() && i0 != x0.rEnd())
                x0.Insert(i0,Tval);
            }
            break;

          case 4:   // void PopFront()
            option = ranint(0,100);
            if (option < removePercent && !x0.Empty())
            {
              x0.PopFront();
              i0 = x0.Begin();
            }
            break;
        
          case 5:   // void PopBack()
            option = ranint(0,100);
            if (option < removePercent && !x0.Empty())
            {
              x0.PopBack();
              i0 = x0.rBegin();
            }
            break;

          case 6:   // void Remove(iter)
            option = ranint(0,100);
            if (option < removePercent && i0.Valid() && i0 != x0.End() && i0 != x0.rEnd())
            {
              i0 = x0.Remove(i0);
            }
            break;

          case 7:   // unsigned int Purge (T)
            option = ranint(0,100);
            if (option < purgePercent)
            {
              Tval = ranobj();
              x0.Remove(Tval);
              i0 = x0.Begin();
            }
            break;

          case 8:   // T& Retrieve() const
            if (i0.Valid())
              Tval = *i0;
            break;

          case 9:   // Begin()
            i0 = x0.Begin();
            break;

          case 10:   // rBegin()
            i0 = x0.rBegin();
            break;

          case 11:   // ++
            if (i0.Valid())
              iter = ++i0;
            else
              i0 = x0.Begin();
            break;

          case 12:   // --
            if (i0.Valid())
              iter = --i0;
            else
              i0 = x0.rBegin();
            break;
        
          case 13:   // ++
            if (i0.Valid())
             iter = i0++;
            else
             i0 = x0.Begin();
            break;
        
          case 14:   // --
            if (i0.Valid())
             iter = i0--;
            else
             i0 = x0.rBegin();
            break;

          case 15:
            if ((x0.Empty()) && (x0.Size() > 0))
              std::cout << "Size() inconsistency in x0\n";
            if ((x0.Size() == 0) && (!x0.Empty()))
              std::cout << "Empty() inconsistency in x0\n";
            break;

          case 16:  // test iterator
            for (iter = x0.Begin(); iter != x0.End(); ++iter)
            {
              Tval = *iter;
            }
            break;

          case 17:
            if (!x0.Empty())
              Tval = x0.Front();
            break;

          case 18:
            if (!x0.Empty())
              Tval = x0.Back();
            break;

          case 19:
            Lptr = x0.Clone();
            delete Lptr;
            break;

          case 20:
            option = ranint(0,100);
            if (option < assignPercent)
            {
              option = ranint(0,numObj);
              switch(option)
              {
                case 0: x0 = x0; break;
                case 1: x0 = x1; break;
                case 2: x0 = x2; break;
                default: std::cout << " ** bad object number in case 0,20\n";
              } // */
              i0 = x0.Begin();
            }
            break;

          case 21:
            option = ranint(0,100);
            if (option < appendPercent)
            {
              option = ranint(0,numObj);
              switch(option)
              {
                case 0: x0 += x0; break;
                case 1: x0 += x1; break;
                case 2: x0 += x2; break;
                default: std::cout << " ** bad object number in case 0,21\n";
              } // */
              // std::cout << " ** x0 += x" << option << '\n';
              i0 = x0.Begin();
            }
            break;

          case 22:
            option = ranint(0,100);
            if (option < assignPercent)
            {
              option = ranint(0,numObj);
              switch(option)
              {
                case 0: x0.Merge(x0); break;
                case 1: x0.Merge(x1); break;
                case 2: x0.Merge(x2); break;
                default: std::cout << " ** bad object number in case 0,22\n";
              } // */
              i0 = x0.Begin();
              i1 = x1.Begin();
              i2 = x2.Begin();
            }
            break;

          case 23:
            x0.Sort();
            break;

          case 24:
            x0.CheckLinks();
            x0.CheckIters();
            break;

          case 25:
            x0.Reverse();
            break;

          default: std::cout << " ** bad operation number in case 0\n";

        }  // end case 0
        break;

      case 1:
        option = ranint(0,numOps); 
        switch (option)
        {

          case 0:   // void Release ()
            capacity = x1.Capacity();
            if (capacity >= maxSize)
            {
              x1.Release();
              i1 = x1.Begin();
              std::cout << "x1 released at capacity " << capacity << std::endl;
            }
            break;

          case 1:   // void PushFront (t)
            option = ranint(0,100);
            if (option < insertPercent)
            {
              Tval = ranobj();
              x1.PushFront(Tval);
            }
            break;
        
          case 2:   // void PushBack (t)
            option = ranint(0,100);
            if (option < insertPercent)
            {
              Tval = ranobj();
              x1.PushBack(Tval);
            }
            break;
        
          case 3:   // void Insert (i1,t)
            option = ranint(0,100);
            if (option < insertPercent)
            {
              Tval = ranobj();
              if (i1.Valid() && i1 != x1.rEnd())
                x1.Insert(i1,Tval);
            }
            break;

          case 4:   // void PopFront()
            option = ranint(0,100);
            if (option < removePercent && !x1.Empty())
            {
              x1.PopFront();
              i1 = x1.Begin();
            }
            break;
        
          case 5:   // void PopBack()
            option = ranint(0,100);
            if (option < removePercent && !x1.Empty())
            {
              x1.PopBack();
              i1 = x1.rBegin();
            }
            break;

          case 6:   // void Remove(iter)
            option = ranint(0,100);
            if (option < removePercent && i1.Valid() && i1 != x1.End() && i1 != x1.rEnd())
            {
              i1 = x1.Remove(i1);
            }
            break;

          case 7:   // unsigned int Purge (T)
            option = ranint(0,100);
            if (option < purgePercent)
            {
              Tval = ranobj();
              x1.Remove(Tval);
              i1 = x1.Begin();
            }
            break;

          case 8:   // T& Retrieve() const
            if (i1.Valid())
              Tval = *i1;
            break;

          case 9:   // Begin()
            i1 = x1.Begin();
            break;

          case 10:   // rBegin()
            i1 = x1.rBegin();
            break;

          case 11:   // ++
            if (i1.Valid())
              iter = ++i1;
            else
              i1 = x1.Begin();
            break;

          case 12:   // --
            if (i1.Valid())
              iter = --i1;
            else
              i1 = x1.rBegin();
            break;
        
          case 13:   // ++
            if (i1.Valid())
             iter = i1++;
            else
             i1 = x1.Begin();
            break;
        
          case 14:   // --
            if (i1.Valid())
             iter = i1--;
            else
             i1 = x1.rBegin();
            break;

          case 15:
            if ((x1.Empty()) && (x1.Size() > 0))
              std::cout << "Size() inconsistency in x1\n";
            if ((x1.Size() == 0) && (!x1.Empty()))
              std::cout << "Empty() inconsistency in x1\n";
            break;

          case 16:  // test iterator
            for (iter = x1.Begin(); iter != x1.End(); ++iter)
            {
              Tval = *iter;
            }
            break;

          case 17:
            if (!x1.Empty())
              Tval = x1.Front();
            break;

          case 18:
            if (!x1.Empty())
              Tval = x1.Back();
            break;

          case 19:
            Lptr = x1.Clone();
            delete Lptr;
            break;

          case 20:
            option = ranint(0,100);
            if (option < assignPercent)
            {
              option = ranint(0,numObj);
              switch(option)
              {
                case 0: x1 = x0; break;
                case 1: x1 = x1; break;
                case 2: x1 = x2; break;
                default: std::cout << " ** bad object number in case 1,20\n";
                } // */
              i1 = x1.Begin();
            }
            break;

          case 21:
            option = ranint(0,100);
            if (option < appendPercent)
            {
              option = ranint(0,numObj);
              switch(option)
              {
                case 0: x1 += x0; break;
                case 1: x1 += x1; break;
                case 2: x1 += x2; break;
                default: std::cout << " ** bad object number in case 1,21\n";
              } // */
              // std::cout << " ** x1 += x" << option << '\n';
              i1 = x1.Begin();
            }
            break;

          case 22:
            option = ranint(0,100);
            if (option < assignPercent)
            {
              option = ranint(0,numObj);
              switch(option)
              {
                case 0: x1.Merge(x0); break;
                case 1: x1.Merge(x1); break;
                case 2: x1.Merge(x2); break;
                default: std::cout << " ** bad object number in case 1,22\n";
              } // */
              i0 = x0.Begin();
              i1 = x1.Begin();
              i2 = x2.Begin();
            }
            break;

          case 23:
            x1.Sort();
            break;

          case 24:
            x1.CheckLinks();
            x1.CheckIters();
            break;

          case 25:
            x1.Reverse();
            break;

          default: std::cout << " ** bad operation number in case 1\n";

        }  // end case 1
        break;
       
      case 2: 
        option = ranint(0,numOps); 
        switch (option)
        {

          case 0:   // void Release ()
            capacity = x2.Capacity();
            if (capacity >= maxSize)
            {
              x2.Release();
              i2 = x2.Begin();
              std::cout << "x2 released at capacity " << capacity << std::endl;
            }
            break;

          case 1:   // void PushFront (t)
            option = ranint(0,100);
            if (option < insertPercent)
            {
              Tval = ranobj();
              x2.PushFront(Tval);
            }
            break;
        
          case 2:   // void PushBack (t)
            option = ranint(0,100);
            if (option < insertPercent)
            {
              Tval = ranobj();
              x2.PushBack(Tval);
            }
            break;
        
          case 3:   // void Insert (i2,t)
            option = ranint(0,100);
            if (option < insertPercent)
            {
              Tval = ranobj();
              if (i2.Valid() && i2 != x2.rEnd())
                x2.Insert(i2,Tval);
            }
            break;

          case 4:   // void PopFront()
            option = ranint(0,100);
            if (option < removePercent && !x2.Empty())
            {
              x2.PopFront();
              i2 = x2.Begin();
            }
            break;
        
          case 5:   // void PopBack()
            option = ranint(0,100);
            if (option < removePercent && !x2.Empty())
            {
              x2.PopBack();
              i2 = x2.rBegin();
            }
            break;

          case 6:   // void Remove(iter)
            option = ranint(0,100);
            if (option < removePercent && i2.Valid() && i2 != x2.End() && i2 != x2.rEnd())
            {
              i2 = x2.Remove(i2);
            }
            break;

          case 7:   // unsigned int Purge (T)
            option = ranint(0,100);
            if (option < purgePercent)
            {
              Tval = ranobj();
              x2.Remove(Tval);
              i2 = x2.Begin();
            }
            break;

          case 8:   // T& Retrieve() const
            if (i2.Valid())
              Tval = *i2;
            break;

          case 9:   // Begin()
            i2 = x2.Begin();
            break;

          case 10:   // rBegin()
            i2 = x2.rBegin();
            break;

          case 11:   // ++
            if (i2.Valid())
              iter = ++i2;
            else
              i2 = x2.Begin();
            break;

          case 12:   // --
            if (i2.Valid())
              iter = --i2;
            else
              i2 = x2.rBegin();
            break;
        
          case 13:   // ++
            if (i2.Valid())
             iter = i2++;
            else
             i2 = x2.Begin();
            break;
        
          case 14:   // --
            if (i2.Valid())
             iter = i2--;
            else
             i2 = x2.rBegin();
            break;

          case 15:
            if ((x2.Empty()) && (x2.Size() > 0))
              std::cout << "Size() inconsistency in x2\n";
            if ((x2.Size() == 0) && (!x2.Empty()))
              std::cout << "Empty() inconsistency in x2\n";
            break;

          case 16:  // test iterator
            for (iter = x2.Begin(); iter != x2.End(); ++iter)
            {
              Tval = *iter;
            }
            break;

          case 17:
            if (!x2.Empty())
              Tval = x2.Front();
            break;

          case 18:
            if (!x2.Empty())
              Tval = x2.Back();
            break;

          case 19:
            Lptr = x2.Clone();
            delete Lptr;
            break;

          case 20:
            option = ranint(0,100);
            if (option < assignPercent)
            {
              option = ranint(0,numObj);
              switch(option)
              {
                case 0: x2 = x0; break;
                case 1: x2 = x1; break;
                case 2: x2 = x2; break;
                default: std::cout << " ** bad object number in case 2,20\n";
              }
              i2 = x2.Begin();
            }
            break;

          case 21:
            option = ranint(0,100);
            if (option < appendPercent)
            {
              option = ranint(0,numObj);
              switch(option)
              {
                case 0: x2 += x0; break;
                case 1: x2 += x1; break;
                case 2: x2 += x2; break;
                default: std::cout << " ** bad object number in case 2,21\n";
              }
              // std::cout << " ** x2 += x" << option << '\n';
              i2 = x2.Begin();
            }
            break;

          case 22:
            option = ranint(0,100);
            if (option < assignPercent)
            {
              option = ranint(0,numObj);
              switch(option)
              {
                case 0: x2.Merge(x0); break;
                case 1: x2.Merge(x1); break;
                case 2: x2.Merge(x2); break;
                default: std::cout << " ** bad object number in case 2,22\n";
              }
              i0 = x0.Begin();
              i1 = x1.Begin();
              i2 = x2.Begin();
            }
            break;

          case 23:
            x2.Sort();
            break;

          case 24:
            x2.CheckLinks();
            x2.CheckIters();
            break;

          case 25:
            x2.Reverse();
            break;

          default: std::cout << " ** bad operation number in case 2\n";

        }  // end case 2
        break;
       

       break;
        default: std::cout << " ** bad object number in main switch\n";

      }   // end switch()

      ++numtrials;
      if (numtrials == reportInterval)
      {
         ++numrpts;
         numtrials = 0;
         std::cout << "\nTesting List < " << vT << " >"
                   << " type A" << a
                   << " at trial " << numrpts << " x " << reportInterval << ":\n"
                   << std::setw(10) << "List" << std::setw(15) << "Size()"  << std::setw(15) << "Excess()"  << '\n' 
                   << std::setw(10) << "----" << std::setw(15) << "------"  << std::setw(15) << "--------"  << '\n' 
                   << std::setw(10) << "x0"   << std::setw(15) << x0.Size() << std::setw(15) << x0.Excess() << '\n' 
                   << std::setw(10) << "x1"   << std::setw(15) << x1.Size() << std::setw(15) << x1.Excess() << '\n' 
                   << std::setw(10) << "x2"   << std::setw(15) << x2.Size() << std::setw(15) << x2.Excess() << '\n' 
                   << std::flush;
      }
      if (maxrpts > 0 && numrpts == maxrpts)
      {
        std::cout << "\nTest Complete\n";
        break;
      }
  }  // end while()
   return EXIT_SUCCESS;
}  // end main()
