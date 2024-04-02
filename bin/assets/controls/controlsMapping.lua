--[[
    src:
        ie_closeWindow          cerrar vebtaba

        ie_keyUp                pulsar tecla
        ie_keyDown              soltar tecla

        ie_mouseMoving          mover ratón
        ie_mouseButtonUp        soltar botón del ratón
        ie_mouseButtonDown      pulsar botón del ratón
        ie_mouseWheel           girar rueda del ratón

        ie_ctrlAxisMotion       mover eje del mando
        ie_ctrlButtonUp         soltar botón del mando
        ie_ctrlButtonDown       pulsar botón del mando

    control:
        (mirar controlValuesGuide.txt y buscar el símbolo - para cada categoría)


    events = {
        ev_NOMBRE_EVENTO = {
            src = origen_del_evento,
            control = valorInputDeSDL
        },
        ...
    }


    PARA MAPEAR EL MISMO EVENTO A VARIOS CONTROLES, AÑADIR AL FINAL DEL NOMBRE DEL EVENTO
    UN _N, SIENDO N UN NÚMERO QUE LO HAGA DIFERENTE DEL RESTO DE EVENTOS CON EL MISMO NOMBRE
    (LUA SOLO SE QUEDA CON EL PRIMER NOMBRE QUE ENCUENTRA DE ENTRE TODOS LOS QUE SON IGUALES)
]]

events = {
    ev_CLOSE = {
        src = "ie_keyDown",
        control = 27    -- SDLK_ESCAPE
    },
	ev_Pause = {
        src = "ie_keyUp",
        control = 112     -- SDLK_p
    },
    ev_MouseButtonDownRight = {
        src = "ie_mouseButtonDown",
        control = 3     -- SDL_BUTTON_RIGHT
    },
    ev_MouseButtonDownLeft = {
        src = "ie_mouseButtonDown",
        control = 1     -- SDL_BUTTON_LEFT
    }

}
