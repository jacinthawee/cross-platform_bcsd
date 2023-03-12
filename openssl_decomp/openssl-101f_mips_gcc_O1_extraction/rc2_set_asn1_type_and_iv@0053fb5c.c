
undefined4 rc2_set_asn1_type_and_iv(EVP_CIPHER_CTX *param_1,int param_2,uchar *param_3,uint param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  uint uVar6;
  int local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    EVP_CIPHER_CTX_ctrl(param_1,2,0,&local_20);
    if (local_20 == 0x80) {
      iVar3 = 0x3a;
    }
    else if (local_20 == 0x40) {
      iVar3 = 0x78;
    }
    else {
      iVar3 = 0xa0;
      if (local_20 != 0x28) {
        iVar3 = 0;
      }
    }
    param_4 = EVP_CIPHER_CTX_iv_length(param_1);
    param_3 = param_1->oiv;
    uVar2 = (*(code *)PTR_ASN1_TYPE_set_int_octetstring_006a9bac)(param_2,iVar3,param_3);
    param_2 = iVar3;
  }
  if (local_1c != *(int *)puVar1) {
    iVar3 = local_1c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (0x3fffffff < param_4) {
      iVar4 = param_2;
      puVar5 = param_3;
      uVar6 = param_4;
      do {
        uVar6 = uVar6 + 0xc0000000;
        (*(code *)PTR_RC2_cbc_encrypt_006a8b44)
                  (puVar5,iVar4,0x40000000,*(int *)(iVar3 + 0x60) + 4,iVar3 + 0x20,
                   *(undefined4 *)(iVar3 + 8));
        puVar5 = puVar5 + 0x40000000;
        iVar4 = iVar4 + 0x40000000;
      } while (0x3fffffff < uVar6);
      uVar6 = param_4 + 0xc0000000;
      param_4 = param_4 & 0x3fffffff;
      iVar4 = ((uVar6 >> 0x1e) + 1) * 0x40000000;
      param_3 = param_3 + iVar4;
      param_2 = param_2 + iVar4;
    }
    if (param_4 != 0) {
      (*(code *)PTR_RC2_cbc_encrypt_006a8b44)
                (param_3,param_2,param_4,*(int *)(iVar3 + 0x60) + 4,iVar3 + 0x20,
                 *(undefined4 *)(iVar3 + 8));
    }
    return 1;
  }
  return uVar2;
}

