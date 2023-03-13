
int PKCS12_gen_mac_part_0(int param_1,char *param_2,int param_3,EVP_MD *param_4,int param_5)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iter;
  undefined4 uVar3;
  EVP_MD *pEVar4;
  int n;
  int iVar5;
  int *piVar6;
  EVP_MD *out;
  char *pcVar7;
  uchar *salt;
  int iVar8;
  undefined4 in_stack_fffffe90;
  undefined auStack_13c [272];
  EVP_MD *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puVar2 = *(undefined4 **)(param_1 + 4);
  out = *(EVP_MD **)PTR___stack_chk_guard_006a9ae8;
  salt = (uchar *)((int *)puVar2[1])[2];
  iVar8 = *(int *)puVar2[1];
  iVar5 = param_3;
  pcVar7 = (char *)param_4;
  local_2c = out;
  if (puVar2[2] == 0) {
    iter = 1;
  }
  else {
    iter = (*(code *)PTR_ASN1_INTEGER_get_006a7208)();
    puVar2 = *(undefined4 **)(param_1 + 4);
  }
  uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)*puVar2);
  uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
  pEVar4 = (EVP_MD *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar3);
  if (pEVar4 == (EVP_MD *)0x0) {
    iVar5 = 0x76;
    pcVar7 = "p12_mutl.c";
    in_stack_fffffe90 = 0x5a;
    out = (EVP_MD *)&DAT_0000006b;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6b,0x76,"p12_mutl.c",0x5a);
    iVar8 = 0;
  }
  else {
    n = (*(code *)PTR_EVP_MD_size_006a7e3c)(pEVar4);
    if (n < 0) {
      iVar8 = 0;
    }
    else {
      out = (EVP_MD *)(auStack_13c + 0xd0);
      iVar8 = PKCS12_key_gen_asc(param_2,param_3,salt,iVar8,3,iter,n,(uchar *)out,pEVar4);
      if (iVar8 == 0) {
        iVar5 = 0x6b;
        pcVar7 = "p12_mutl.c";
        in_stack_fffffe90 = 0x62;
        out = (EVP_MD *)&DAT_0000006b;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6b,0x6b,"p12_mutl.c",0x62);
      }
      else {
        (*(code *)PTR_HMAC_CTX_init_006a7a1c)(auStack_13c);
        in_stack_fffffe90 = 0;
        iVar5 = (*(code *)PTR_HMAC_Init_ex_006a7acc)(auStack_13c,out,n,pEVar4,0);
        if (iVar5 != 0) {
          piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x14);
          n = *piVar6;
          out = (EVP_MD *)piVar6[2];
          iVar5 = (*(code *)PTR_HMAC_Update_006a7ad0)(auStack_13c,out,n);
          if (iVar5 != 0) {
            iVar5 = (*(code *)PTR_HMAC_Final_006a7ad4)(auStack_13c,param_4,param_5);
            out = param_4;
            n = param_5;
            if (iVar5 != 0) {
              (*(code *)PTR_HMAC_CTX_cleanup_006a7adc)(auStack_13c);
              iVar8 = 1;
              out = param_4;
              iVar5 = param_5;
              pcVar7 = (char *)pEVar4;
              goto LAB_005a9ff8;
            }
          }
        }
        (*(code *)PTR_HMAC_CTX_cleanup_006a7adc)(auStack_13c);
        iVar8 = 0;
        iVar5 = n;
        pcVar7 = (char *)pEVar4;
      }
    }
  }
LAB_005a9ff8:
  if (local_2c == *(EVP_MD **)puVar1) {
    return iVar8;
  }
  pEVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar8 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)(pEVar4->md_size + 0x10));
  if (iVar8 == 0x15) {
    iVar5 = PKCS12_gen_mac_part_0(pEVar4,out,iVar5,pcVar7,in_stack_fffffe90);
    return iVar5;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6b,0x79,"p12_mutl.c",0x4f);
  return 0;
}

