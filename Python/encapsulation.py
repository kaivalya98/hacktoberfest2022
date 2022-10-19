#Encapsulation
#encapsulation is the defining of the data and the methods in just one block like class
class PlayerCharacter():
  def __init__(self,name,age):
    self.name=name
    self.age=22
  def run():
    print("Run")
  def speak(self):
    print(f'My name is {self.name} and my age is {self.age} years old')
player1=PlayerCharacter("aman",22)
print(player1.name)
player1.speak()
