
void X509_STORE_free(X509_STORE *v)

{
  int iVar1;
  int iVar2;
  int iVar3;
  stack_st_X509_LOOKUP *psVar4;
  
  if (v == (X509_STORE *)0x0) {
    return;
  }
  psVar4 = v->get_cert_methods;
  iVar3 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar4);
    if (iVar2 <= iVar3) {
      (*(code *)PTR_sk_free_006a7f80)();
      (*(code *)PTR_sk_pop_free_006a8158)(v->objs,cleanup);
      (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(4,v,&v->ex_data);
      if (v->param != (X509_VERIFY_PARAM *)0x0) {
        X509_VERIFY_PARAM_free(v->param);
      }
                    /* WARNING: Could not recover jumptable at 0x00583918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a7f88)(v);
      return;
    }
    iVar2 = (*(code *)PTR_sk_value_006a7f24)(psVar4,iVar3);
    iVar1 = *(int *)(iVar2 + 8);
    if (iVar1 != 0) {
      if (*(code **)(iVar1 + 0x10) != (code *)0x0) {
        (**(code **)(iVar1 + 0x10))(iVar2);
        iVar1 = *(int *)(iVar2 + 8);
        if (iVar1 == 0) goto LAB_0058386c;
      }
      if (*(code **)(iVar1 + 8) != (code *)0x0) {
        (**(code **)(iVar1 + 8))(iVar2);
      }
    }
LAB_0058386c:
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    iVar3 = iVar3 + 1;
  } while( true );
}

