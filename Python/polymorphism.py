#Polymorphism
#using same function and getting different output is called Polymorphism as in example attack() is used.
class User():
  def login():
    print("you are logged in ")
  def attack(self):
    print("Do nothing")
class Wizard(User):
  def __init__(self,name,power):
    self.name=name
    self.power=power
  def attack(self):
    User.attack(self)
    print(f"attacking with the power of {self.name}")

class Archer():
  def __init__(self, name,arrows):
    self.name=name
    self.arrows=arrows
  def attack(self):
    print(f'attacking with the arrows {self.arrows}')
wizard1=Wizard("aman",100)
archer1=Archer("prince",50)
wizard1.attack()
archer1.attack()
