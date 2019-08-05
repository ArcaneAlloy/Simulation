#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


class trait
{
	friend class unit;
	friend class Simulation;
	friend class Loan;
private:
	int traits[4];
public:
	void set_traits(int base = 30, int max = 60, int trait3 = 0, int trait4 = 0, bool special = false)
	{
		for (int i = 0; i <= 3; i++) { traits[i] = base; }
		if (special == false)
		{
			int num = rand() % max;
			traits[3] += num;
			num /= 3;
			for (int a = 0; a <= 2; a++)
			{
				if (traits[a] >= num) { traits[a] -= num; }
			}
			for (int i = 0; i <= 2; i++)
			{
				int num = rand() % max;
				traits[i] += num;
				num /= 3;
				for (int a = 0; a <= 3; a++)
				{
					if (a != i && traits[a] >= num) { traits[a] -= num; }
				}
			}
			traits[2] += 30;
		}
		else
		{
			traits[0] = base;
			traits[1] = max;
			traits[2] = trait3;
			traits[3] = trait4;
		}
	}

	void display()
	{
		cout << "a: " << traits[0] << " s: " << traits[1] << "  int: " << traits[2] << " imm: " << traits[3] << "\n";
	}
};

class unit
{
	friend class Simulation;
	friend class Loan;
private:
	int gathered = 0;
	bool specialized = false;
	bool unbounded = false;
	bool siphon = false;
	bool transmutation = false;
	bool vigilante = false;
	bool killer = false;
	bool loaner = false;
	bool God = false;
	trait determinant;
public: 
	unit()
	{
		determinant.set_traits();
		specialize();
		update_determinant();
		if (God) { cout << "GOD HAS MANIFESTED\n"; }
	}

	unit(const unit& object, bool copy)
	{
		determinant = object.determinant;
		if (object.specialized == false) { specialize(); }
		else
		{
			if (object.unbounded) { unbounded = true; }
			else if (object.siphon) { siphon = true; }
			else if (object.transmutation) { transmutation = true; }
			else if (object.vigilante) { vigilante = true; }
			else if (object.killer) { killer = true; }
			else if (object.loaner) { loaner = true; }
			else if (object.God) { God = true; }
			specialized = true;
		}
		update_determinant();
		if (God) { cout << "GOD HAS MANIFESTED\n"; }
		int num = 1 + rand() % 500;
		if (num == 500)
		{
			int num = 1 + rand() % 2;
			if (num == 1)
			{
				for (int i = 1; i <= 1; i++) { determinant.traits[i] += 6; determinant.traits[i + 2] -= 6; }
			}
			else
			{
				for (int i = 3; i >= 2; i--) { if (determinant.traits[i] >= 6) { determinant.traits[i] -= 6; determinant.traits[i - 2] += 6; } }
			}
		}
	}

	bool operator == (const unit& u1)
	{
		bool equal = true;
		for (int i = 0; i <= 3; i++)
		{
			if (u1.determinant.traits[i] != this->determinant.traits[i])
			{
				equal = false;
				break;
			}
		}
		if (equal)
		{
			if (u1.specialized && (this->specialized == false)) { cout << "1\n";  return false; }
			else if ((u1.specialized == false) && this->specialized) { cout << "2\n"; return false; }
			return true;
		}
		return false;
	}

	void specialize()
	{
		int num = 1 + rand() % 32000;
		if (specialized == false)
		{
			if (num <= 640)
			{
				int num2 = 1 + rand() % 6;
				switch (num2)
				{
				case 1: unbounded = true; cout << "unbounded born\n"; break;
				case 2: siphon = true; cout << "siphon born\n"; break;
				case 3: transmutation = true; cout << "transmutation born\n"; break;
				case 4: vigilante = true; cout << "vigilante born\n"; break;
				case 5: killer = true; cout << "killer born\n"; break;
				case 6: loaner = true; cout << "loaner born\n"; break;
				}
				specialized = true;
			}
		}
	}
 
	void update_determinant()
	{
		if (specialized)
		{
			if (unbounded) { determinant.set_traits(45, 30, 50, 10, true); }
			else if (siphon) { determinant.set_traits(30, 30, 60, 10, true); }
			else if (transmutation) { determinant.set_traits(30, 50, 70, 30, true); }
			else if (vigilante) { determinant.set_traits(0, 0, 0, 100, true); }
			else if (killer) { determinant.set_traits(0, 0, 0, 0, true); }
			else if (loaner) { determinant.set_traits(40, 100, 70, 100 , true); }
			else if (God) { determinant.set_traits(100, 100, 100, 100, true); }
		}
	}

	void make_specal()
	{
		loaner = true;
		specialized = true;
		update_determinant();
	}

};

struct elem
{
	unit u1;
	vector<unit>::iterator loc;
};

class Loan
{
	friend class Simulation;
private:
	unit donor;
	unit recipient;
public:
	Loan(unit& don, unit& rec) : donor(don), recipient(rec) {}

	void pay(vector<Loan>& loanList, vector<unit>& grp)
	{
		vector<Loan>::iterator loans;
		vector<unit>::iterator match;
		for (loans = loanList.begin(); loans < loanList.end(); loans++)
		{
			loans->donor.gathered = 0;
			for (match = grp.begin(); match < grp.end(); match++)
			{
				if (*match == loans->recipient) { match->gathered--; loans->donor.gathered++; }
			}
			for (match = grp.begin(); match < grp.end(); match++)
			{
				if (*match == loans->donor) { match->gathered += loans->donor.gathered; break; }
			}
			loans->donor.gathered = 0;
		}
	}
};

class Simulation
{
	friend class Loan;
private: 
	vector<int> killList;
	vector<Loan> loans;
	vector<unit> pop;
	vector<unit> pop2;
	static int maxvigpop;
	static int maxkillpop;
	int food = 100;

	bool searchList(int num)
	{
		vector<int>::iterator match;
		for (match = killList.begin(); match < killList.end(); match++)
		{
			if (*match == num) { return true; }
		}
		return false;
	}

	bool searchLoans(unit& u1)
	{
		vector<Loan>::iterator match;
		for (match = loans.begin(); match < loans.end(); match++)
		{
			if (match->recipient == u1) { return true; }
		}
		return false;
	}

	void clearKillList2(vector<unit>& grp)
	{
		int loc = 0;
		vector<int>::iterator reaper;
		for (reaper = killList.begin(); reaper < killList.end(); reaper++)
		{
			vector<int>::iterator subreap;
			bool skip = false;
			for (subreap = reaper; subreap < killList.end(); subreap++)
			{
				if (subreap != reaper && *subreap == *reaper) { skip = true; break; }
			}
			if (skip) { continue; }
			for (subreap = killList.begin(); subreap < killList.end(); subreap++)
			{
				if (*subreap > *reaper)
				{
					(*subreap)--;
				}
			}
			grp.erase(grp.begin() + *reaper);
			loc++;
		}
		killList.clear();
	} 
	
	void clearLoans(vector<unit>& grp)
	{
		vector<int> endList;
		vector<Loan>::iterator obj;
		vector<unit>::iterator match;
		int loc = 0;
		for (obj = loans.begin(); obj < loans.end(); obj++)
		{
			for (match = grp.begin(); match < grp.end(); match++)
			{
				if (*match == obj->recipient)
				{
					if (match->gathered < 1) { endList.push_back(loc); break; }
				}
				else if (*match == obj->donor)
				{
					if (match->gathered < 1) { endList.push_back(loc); break; }
				}
			}
			loc++;
		}
		vector<int>::iterator reaper;
		for (reaper = endList.begin(); reaper < endList.end(); reaper++)
		{
			vector<int>::iterator subreap;
			for (subreap = endList.begin(); subreap < endList.end(); subreap++)
			{
				if (*subreap > *reaper)
				{
					(*subreap)--;
				}
			}
			loans.erase(loans.begin() + *reaper);
		}
	}
	
	void payLoans(vector<unit>& grp)
	{
		if (loans.size() > 0)
		{
			loans.begin()->pay(loans, grp);
		}
	}

	void sort2(vector<unit>& curr, vector<unit>& next)
	{
		elem * max = new elem;
		while (curr.size() > 0)
		{
			max->u1 = *curr.begin();
			max->loc = curr.begin();
			vector<unit>::iterator it;
			for (it = curr.begin() + 1; it < curr.end(); it++)
			{
				if (it->determinant.traits[0] > max->u1.determinant.traits[0])
				{
					max->u1 = *it;
					max->loc = it;
				}
			}
			next.push_back(max->u1);
			curr.erase(max->loc);
		}
	}

	void eat2(vector<unit>& grp)
	{
		vector<unit>::iterator iter;
		int loc1 = 0;
		for (iter = grp.begin(); iter < grp.end(); iter++)
		{
			int num = 1 + rand() % 100;
			if (food > 0 && num <= iter->determinant.traits[2])
			{
				num = 1 + rand() % 100;
				if (num <= iter->determinant.traits[1] && iter->gathered <= 3) { (iter->gathered) += 2; food -= 2; }
				else { (iter->gathered)++; food--; }
			}
			loc1++;
		}
		payLoans(grp);
		behaviors();
		clearLoans(grp);
		int loc = 0;
		for (iter = grp.begin(); iter < grp.end(); iter++)
		{
			if (iter->gathered < 1)
			{
				killList.push_back(loc);
			}
			iter->gathered--;
			loc++;
		}
		clearKillList();
		cout << "group size: " << grp.size() << "\n";
	}

	void behaviors2(vector<unit>& grp)
	{
		vector<unit>::iterator iter;
		int loc = -1;
		for (iter = grp.begin(); iter < grp.end(); iter++)
		{
			loc++;
			if (iter->specialized)
			{
				if (iter->unbounded)
				{
					for (int i = 0; i <= 3; i++)
					{
						if (iter->determinant.traits[i] <= 95) { iter->determinant.traits[i] += 5; }
					}
				}
				else if (iter->siphon)
				{
					int num = 1 + rand() % 100;
					if (num <= 5) { killList.push_back(loc); continue; }
					num = rand() % grp.size();
					unit * recipient = &(*(grp.begin() + num));
					num = 1 + rand() % 100;
					if (num < recipient->determinant.traits[3]) { continue; }
					for (int i = 0; i <= 3; i++)
					{
						if (recipient->determinant.traits[i] >= 5) { recipient->determinant.traits[i] -= 5; }
						if (iter->determinant.traits[i] <= 95) { iter->determinant.traits[i] += 5; }
					}
				}
				else if (iter->transmutation)
				{
					if (iter->gathered < 1)
					{
						int changed = 0;
						for (int i = 0; i <= 3; i++)
						{
							if (iter->determinant.traits[i] >= 15) { iter->determinant.traits[i] -= 15; changed++; }
						}
						if (changed >= 2)
						{
							iter->gathered++;
						}
					}
					else if (iter->gathered > 2)
					{
						for (int i = 0; i <= 3; i++)
						{
							if (iter->determinant.traits[i] <= 95) { iter->determinant.traits[i] += 5; }
						}
						iter->gathered -= 2;
					}
				}
				else if (iter->vigilante)
				{
					vector<unit>::iterator search;
					int subloc = 0;
					for (search = grp.begin(); search < grp.end(); search++)
					{
						if (search->killer && (searchList(subloc) == false)) 
						{ 
							killList.push_back(subloc); 
							iter->gathered += (grp.begin() + subloc)->gathered;
							break;
						}
						subloc++;
					}
				}
				else if (iter->killer) 
				{
					int count = 0;
					while (count < 3)
					{
						int num1 = rand() % grp.size();
						unit * recipient = &(*(grp.begin() + num1));
						if (searchList(num1) == false)
						{
							int num2 = 1 + rand() % 100;
							if (num2 > recipient->determinant.traits[3] && recipient->killer == false) 
							{ 
								killList.push_back(num1); 
								iter->gathered += recipient->gathered; 
								break; 
							}
						}
						count++;
					}
				}
				else if (iter->loaner)
				{
					int recipient1 = willDie();
					if (iter->gathered > 1 && recipient1 != -1)
					{
						vector<unit>::iterator recipient2 = grp.begin() + recipient1;
						if (recipient2->determinant.traits[1] <= 70) { recipient2->determinant.traits[1] += 30; }
						recipient2->gathered++;
						iter->gathered--;
						Loan * loan = new Loan(*iter, *recipient2);
						loans.push_back(*loan);
					}
				}
			}
		}
	}

	void replicate2(vector<unit>& grp)
	{
		vector<unit>::iterator iter;
		vector<unit> units;
		for (iter = grp.begin(); iter < grp.end(); iter++)
		{
			if (iter->gathered >= 1)
			{
				unit * u1 = new unit(*iter, true);
				units.push_back(*u1);
				iter->gathered-- ;
			}
		}
		for (iter = units.begin(); iter < units.end(); iter++)
		{
			grp.push_back(*iter);
		}
	}
	
public:
	Simulation()
	{
		for (int i = 0; i < 50; i++)
		{
			unit * u1 = new unit;
			pop.push_back(*u1);
		}
	}

	void add(unit& u1)
	{
		pop.push_back(u1);
	}

	void clearKillList()
	{
		if (pop.size() > 0) { clearKillList2(pop); }
		else { clearKillList2(pop2); }
	}

	void sort()
	{
		if (pop.size() > 0) { sort2(pop, pop2); }
		else { sort2(pop2, pop); }
	}

	void eat()
	{
		if (pop.size() > 0) { eat2(pop); }
		else { eat2(pop2); }
	}

	int willDie()
	{
		vector<unit> * list;
		if (pop.size() > 0) { list = &pop; }
		else { list = &pop2; }
		vector<unit>::iterator it;
		int loc = 0;
		for (it = list->begin(); it < list->end(); it++)
		{
			if (it->gathered < 1 && searchLoans(*it) == false) { return loc; }
			loc++;
		}
		return -1;
	}

	void behaviors()
	{
		if (pop.size() > 0) { behaviors2(pop); }
		else { behaviors2(pop2); }
	}

	void replicate()
	{
		if (pop.size() > 0) { replicate2(pop); }
		else { replicate2(pop2); }
	}

	void set_food(int var) { food = var; }

	void display()
	{
		vector<unit> list;
		if (pop.size() > 0) { list = pop; }
		else { list = pop2; }
		vector<unit>::iterator iter;
		for (iter = list.begin(); iter < list.end(); ++iter)
		{
			iter->determinant.display();
		}
		cout << "-------------------------------\n"; 
	}

	void display2(int max)
	{
		vector<unit> * list;
		if (pop.size() > 0) { list = &pop; }
		else { list = &pop2; }
		vector<unit>::iterator read;
		int highaggr = 0; int highspeed = 0;
		int highint = 0; int highimm = 0; 
		int unbpop = 0; int siphpop = 0; int trapop = 0; 
		int vigpop = 0; int killpop = 0; int loanpop = 0; 
		int Godpop = 0;
		for (read = list->begin(); read < list->end(); read++)
		{
			if (read->unbounded) { unbpop++; }
			if (read->siphon) { siphpop++; }
			if (read->transmutation) { trapop++; }
			if (read->vigilante) { vigpop++; if (vigpop > maxvigpop) { maxvigpop = vigpop; } }
			if (read->killer) { killpop++; if (killpop > maxkillpop) { maxkillpop = killpop; } }
			if (read->loaner) { loanpop++; }
			if (read->God) { Godpop++; }
			if (read->determinant.traits[0] > max) { highaggr++; }
			if (read->determinant.traits[1] > max) { highspeed++; }
			if (read->determinant.traits[2] > max) { highint++; }
			if (read->determinant.traits[3] > max) { highimm++; }
		}
		for (int i = 100; i >= 0; i -= 10)
		{
			if (i == 100) { cout << i << " :"; }
			else if (i == 0) { cout << i << "   :"; }
			else { cout << i << "  :"; }
			if (highaggr > i) { cout << "\tO"; } else { cout << "\t "; }
			if (highspeed > i) { cout << "\tO"; } else { cout << "\t "; }
			if (highint > i) { cout << "\tO"; } else { cout << "\t "; }
			if (highimm > i) { cout << "\tO"; } else { cout << "\t "; }
			if (unbpop > i / 10) {cout << "\tO"; } else { cout << "\t "; }
			if (siphpop > i / 10) { cout << "\tO"; } else { cout << "\t "; }
			if (trapop > i / 10) { cout << "\tO"; } else { cout << "\t "; }
			if (vigpop > i / 10) { cout << "\tO"; } else { cout << "\t "; }
			if (killpop > i / 10) { cout << "\tO"; } else { cout << "\t "; }
			if (loanpop > i / 10) { cout << "\tO"; } else { cout << "\t "; }
			if (Godpop > i / 10) { cout << "\tO"; } else { cout << "\t "; }
			if (maxvigpop > i / 10) { cout << "\tO"; } else { cout << "\t "; }
			if (maxkillpop > i / 10) { cout << "\tO"; } else { cout << "\t "; }
			cout << "\n\n";
		}
		cout << "     \tA\tS\tI\tI\tU\tS\tT\tV\tK\tL\tG\tV\tK\n\n";
	}
};

int Simulation::maxkillpop = 0;
int Simulation::maxvigpop = 0;

int main()
{
	srand(time(NULL));

	Simulation sim1; 
	int count = 0;
	while (count <= 100)
	{
		sim1.set_food(100);
		sim1.sort();
		sim1.eat();
		if (count % 10 == 0) { sim1.display2(70); system("PAUSE"); }
		sim1.replicate();
		count++;
	}

	system("PAUSE");
	return 0;
};