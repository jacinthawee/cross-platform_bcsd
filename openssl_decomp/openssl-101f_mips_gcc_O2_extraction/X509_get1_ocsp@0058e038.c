
stack_st_OPENSSL_STRING * X509_get1_ocsp(X509 *x)

{
  AUTHORITY_INFO_ACCESS *a;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  stack_st_OPENSSL_STRING *psVar5;
  
  a = (AUTHORITY_INFO_ACCESS *)X509_get_ext_d2i(x,0xb1,(int *)0x0,(int *)0x0);
  if (a == (AUTHORITY_INFO_ACCESS *)0x0) {
    psVar5 = (stack_st_OPENSSL_STRING *)0x0;
  }
  else {
    iVar3 = 0;
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(a);
    psVar5 = (stack_st_OPENSSL_STRING *)0x0;
    if (0 < iVar1) {
      do {
        puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(a,iVar3);
        iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar2);
        if ((((iVar1 == 0xb2) && (*(int *)puVar2[1] == 6)) &&
            (piVar4 = (int *)((int *)puVar2[1])[1], piVar4[1] == 0x16)) &&
           ((iVar1 = piVar4[2], iVar1 != 0 && (*piVar4 != 0)))) {
          if (psVar5 == (stack_st_OPENSSL_STRING *)0x0) {
            psVar5 = (stack_st_OPENSSL_STRING *)(*(code *)PTR_sk_new_006a91b4)(sk_strcmp);
            if (psVar5 != (stack_st_OPENSSL_STRING *)0x0) {
              iVar1 = piVar4[2];
              goto LAB_0058e184;
            }
          }
          else {
LAB_0058e184:
            iVar1 = (*(code *)PTR_sk_find_006a906c)(psVar5,iVar1);
            if ((iVar1 != -1) ||
               ((iVar1 = (*(code *)PTR_BUF_strdup_006a80dc)(piVar4[2]), iVar1 != 0 &&
                (iVar1 = (*(code *)PTR_sk_push_006a80a8)(psVar5,iVar1), iVar1 != 0))))
            goto LAB_0058e0f0;
            (*(code *)PTR_sk_pop_free_006a8158)(psVar5,str_free);
          }
          psVar5 = (stack_st_OPENSSL_STRING *)0x0;
          break;
        }
LAB_0058e0f0:
        iVar3 = iVar3 + 1;
        iVar1 = (*(code *)PTR_sk_num_006a7f2c)(a);
      } while (iVar3 < iVar1);
    }
    AUTHORITY_INFO_ACCESS_free(a);
  }
  return psVar5;
}
