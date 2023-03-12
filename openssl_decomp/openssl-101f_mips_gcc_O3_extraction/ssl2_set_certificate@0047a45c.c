
uint ssl2_set_certificate(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  undefined4 local_resc;
  
  local_resc = param_4;
  iVar2 = (*(code *)PTR_d2i_X509_006a9070)(0,&local_resc);
  if (iVar2 == 0) {
    uVar9 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x7e,0xb,"s2_clnt.c",0x40f);
    piVar8 = (int *)0x0;
    iVar3 = 0;
    goto LAB_0047a504;
  }
  iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
  if (iVar3 == 0) {
LAB_0047a4d4:
    uVar7 = 0x41;
    uVar5 = 0x415;
  }
  else {
    iVar4 = (*(code *)PTR_sk_push_006a80a8)(iVar3,iVar2);
    if (iVar4 == 0) goto LAB_0047a4d4;
    iVar4 = (*(code *)PTR_ssl_verify_cert_chain_006a9078)(param_1,iVar3);
    if ((*(int *)(param_1 + 200) == 0) || (0 < iVar4)) {
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      puVar1 = PTR_ssl_sess_cert_new_006a9060;
      *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xa0) = *(undefined4 *)(param_1 + 0xec);
      iVar4 = (*(code *)puVar1)();
      if (iVar4 == 0) {
        uVar9 = 0xffffffff;
        piVar8 = (int *)0x0;
      }
      else {
        iVar6 = *(int *)(param_1 + 0xc0);
        if (*(int *)(iVar6 + 0x98) != 0) {
          (*(code *)PTR_ssl_sess_cert_free_006a905c)();
          iVar6 = *(int *)(param_1 + 0xc0);
        }
        puVar1 = PTR_X509_get_pubkey_006a8008;
        *(int *)(iVar6 + 0x98) = iVar4;
        *(int *)(iVar4 + 0xc) = iVar2;
        *(int *)(iVar4 + 8) = iVar4 + 0xc;
        piVar8 = (int *)(*(code *)puVar1)(iVar2);
        if (piVar8 == (int *)0x0) {
          uVar7 = 0xed;
          uVar5 = 0x434;
        }
        else {
          if (*piVar8 == 6) {
            iVar2 = 0;
            iVar4 = (*(code *)PTR_ssl_set_peer_cert_type_006a9084)(iVar4,1);
            uVar9 = (uint)(iVar4 != 0);
            goto LAB_0047a504;
          }
          uVar7 = 0xd2;
          uVar5 = 0x439;
        }
        uVar9 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x7e,uVar7,"s2_clnt.c",uVar5);
        iVar2 = 0;
      }
      goto LAB_0047a504;
    }
    uVar7 = 0x86;
    uVar5 = 0x41d;
  }
  uVar9 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x7e,uVar7,"s2_clnt.c",uVar5);
  piVar8 = (int *)0x0;
LAB_0047a504:
  (*(code *)PTR_sk_free_006a7f80)(iVar3);
  (*(code *)PTR_X509_free_006a7f90)(iVar2);
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar8);
  return uVar9;
}

