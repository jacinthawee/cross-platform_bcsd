
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509V3_EXT_cleanup(void)

{
  undefined4 in_a2;
  undefined4 in_a3;
  
  (*(code *)PTR_sk_pop_free_006a7058)(ext_list,ext_list_free,in_a2,in_a3,&_gp);
  ext_list = 0;
  return;
}

