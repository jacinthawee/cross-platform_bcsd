
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_load_dynamic(void)

{
  ENGINE *e;
  int iVar1;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,"dynamic");
  if ((((iVar1 != 0) && (iVar1 = ENGINE_set_name(e,"Dynamic engine loading support"), iVar1 != 0))
      && (iVar1 = ENGINE_set_init_function(e,dynamic_init + 1), iVar1 != 0)) &&
     (((iVar1 = ENGINE_set_finish_function(e,dynamic_finish + 1), iVar1 != 0 &&
       (iVar1 = ENGINE_set_ctrl_function(e,dynamic_ctrl + 1), iVar1 != 0)) &&
      ((iVar1 = ENGINE_set_flags(e,4), iVar1 != 0 &&
       (iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)&dynamic_cmd_defns), iVar1 != 0)))))) {
    ENGINE_add(e);
    ENGINE_free(e);
    ERR_clear_error();
    return;
  }
  ENGINE_free(e);
  return;
}

