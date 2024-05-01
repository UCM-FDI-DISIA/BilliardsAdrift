function comp:start()
	self.time = 0
end

function comp:initComponent(variables)
	if type(variables.changeTime) ~= "number" then
		error("La variable changeTime no es un numero.")
	end
	self.changeTime = variables.changeTime
	self.splashScene = variables.splashScene
	self.mainScene = variables.mainScene
end

function comp:update(deltaTime)
	if self.time >= self.changeTime and not self.done then
		Tapioca.deleteScene(self.splashScene)
		Tapioca.loadScene(self.mainScene)
		self.done = true
	elseif not self.done then
		self.time = self.time + deltaTime
	end
end