local CXHelloWorld = class("CXHelloWorld", function()
	return display.newScene("CXHelloWorld")
end)

function CXHelloWorld:ctor()
	display.newSprite("HelloWorld.png")
		:addTo(self)
		:center()

	display.newTTFLabel({text = "Hello, World", size = 64, color = display.COLOR_YELLOW})
		:align(display.CENTER, display.cx, display.cy)
		:addTo(self)
end

function CXHelloWorld:onEnter()
end

function CXHelloWorld:onExit()
end

return CXHelloWorld