use_base_code = os.exists("Source")
if use_base_code then
    includes("xmgr/basecode.lua")
else
    includes("xmgr/import_code.lua")
end

includes("xmgr/tutorial.lua")