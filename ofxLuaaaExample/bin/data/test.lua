local d = draw.new();

function setup()
	print("Hello from Lua!")
end

function update()
end

function draw()
	d:awesomeFunction(30)
end

function exit()
	print("Goodbye from Lua!")
end
