function debug(text)
	print("Se hizo clic/enter: " .. text)
end

function play()
	Tapioca.loadScene("Level1")
	Tapioca.deleteScene("MainMenu")
	-- Cambiar el estado del juego
end