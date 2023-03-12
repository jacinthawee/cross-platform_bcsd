
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_VERIFY_PARAM_table_cleanup(void)

{
  undefined4 in_a2;
  undefined4 in_a3;
  
  if (param_table != 0) {
    (*(code *)PTR_sk_pop_free_006a8158)(param_table,X509_VERIFY_PARAM_free,in_a2,in_a3,&_gp);
  }
  param_table = 0;
  return;
}

