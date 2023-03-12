
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_add_conf_module(void)

{
                    /* WARNING: Could not recover jumptable at 0x00605078. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CONF_module_add_006aa8b0)("engines",int_engine_module_init,int_engine_module_finish)
  ;
  return;
}

