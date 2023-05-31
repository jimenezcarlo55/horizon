local skill_id = ...

local skill_db = require("db/skill_db")

local function find_skill_by_id(skill_id)
	for k, v in pairs(skill_db) do
		if v["Id"] == skill_id then
			return v
		end
	end
	return nil
end

return find_skill_by_id