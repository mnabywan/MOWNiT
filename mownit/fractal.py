from PIL import Image
#granice obrazka
x_min = -1.0
x_max = 1.0

y_min = -1.0
y_max = 1.0

#wspolczynniki do kontrolowania algorytmu
nmax = 50 
high = 10e10 
epsilon = 10e-10
delta = 10e-5

colors = [(255,255,0),(255,69,0),(50,205,50),(0,191,255),(123,104,238),(0,0,0)] #kolory: zolty, czerwony, zielony, niebieski, fioletowy, czarny

#definicje funkcji z^5+1 i jej pochodnej 5*z^4
def function(z): return z * z * z - 1.0
def dfunction(z) : return 3*z*z 

def newtons_method(f, df, z):
    for i in range(nmax): 
        d = f(z)/df(z)

        if abs(f(z)) > high:
             return None
       
        if abs(f(z)) < epsilon:
            return None
       
        if abs(d) < delta:
            return z
        z = z - d
    return None


#funkcja odpowiadajaca za rysowanie fraktala 
def draw(f, df, img, size, img_name):
    roots = [] #tablica na piewiastki 
    for y in range(size):
        z_y = y * (y_max - y_min)/(size - 1) + y_min
        for x in range(size):
            z_x = x * (x_max - x_min)/(size - 1) + x_min
            root = newtons_method(f, df, complex(z_x, z_y))  
            if root:
                flag = False
                for  test_root in roots:
                    if abs(test_root - root) < 10e-3:
                        root = test_root
                        flag = True
                        break
                if not flag:
                    roots.append(root)
            if root:
                img.putpixel((x, y), colors[roots.index(root)])
	    if not root:
		img.putpixel((x,y), colors[5])
    print roots
    img.save(img_name, "PNG")
 
size = 1024 
img = Image.new("RGB", (size, size), (255, 255, 255))
draw(lambda z: function(z), lambda z: dfunction(z), img, size, "MyNewtonFractal11");
