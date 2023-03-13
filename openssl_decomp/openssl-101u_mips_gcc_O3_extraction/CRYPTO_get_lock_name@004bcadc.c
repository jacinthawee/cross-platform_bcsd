
char * CRYPTO_get_lock_name(int type)

{
  int iVar1;
  char *pcVar2;
  
  if (type < 0) {
    return "dynamic";
  }
  if (type < 0x29) {
    return *(char **)(lock_names + type * 4);
  }
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(app_locks);
  if (iVar1 < type + -0x29) {
    return "ERROR";
  }
                    /* WARNING: Could not recover jumptable at 0x004bcb78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar2 = (char *)(*(code *)PTR_sk_value_006a6e24)(app_locks,type + -0x29);
  return pcVar2;
}

