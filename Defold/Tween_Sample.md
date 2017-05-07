### Tween Animation

[Reference](http://www.defold.com/ref/go/#go.animate:url-property-playback-to-easing-duration--delay---complete_function-)

go.animate(url,property,playback,to,easing,duration)


---
    local tween_queue =
    {
        items = {},
        add = function(self,targetid,destpos,duration)


            table.insert(self.items,
            {
                id = targetid,
                start = go.get_position(targetid),
                dest = destpos,
                d = duration,
                t = 0
            })
        end,
        update = function(self,deltatime)

            for k,v in pairs(self.items) do

                v.t = v.t + deltatime

                if v.start.x ~= v.dest.x then
                    go.set(v.id, "position.x", v.dest.x*v.t/v.d+v.start.x)
                end
                if v.start.y ~= v.dest.y then
                    go.set(v.id, "position.y", v.dest.y*v.t/v.d+v.start.y)
                end
                if v.start.z ~= v.dest.z then
                    go.set(v.id, "position.z", v.dest.z*v.t/v.d+v.start.z)
                end
                --[[go.set_position(vmath.vector3(
                    v.dest.x*v.t/v.d+v.start.x,
                    v.dest.y*v.t/v.d+v.start.y,
                    v.dest.z*v.t/v.d+v.start.z
                ), v.id)--]]

                if v.t >= v.d then
                    table.remove(self.items,k)
                end
            end
        end
    }
---
