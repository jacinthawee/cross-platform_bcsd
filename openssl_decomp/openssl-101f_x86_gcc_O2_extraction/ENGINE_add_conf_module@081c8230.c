
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_add_conf_module(void)

{
  CONF_module_add("engines",int_engine_module_init,int_engine_module_finish);
  return;
}

