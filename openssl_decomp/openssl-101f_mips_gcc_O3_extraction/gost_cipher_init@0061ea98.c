
undefined4 gost_cipher_init(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  
  piVar9 = *(int **)(param_1 + 0x60);
  if (*(int *)(param_1 + 0x54) != 0) goto LAB_0061ead4;
  pcVar2 = (char *)get_gost_engine_param(0);
  if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
    piVar5 = (int *)(gost_cipher_list + 0xc);
    iVar7 = gost_cipher_list._16_4_;
    iVar8 = gost_cipher_list._12_4_;
LAB_0061eba0:
    iVar3 = piVar5[2];
  }
  else {
    iVar4 = (*(code *)PTR_OBJ_txt2nid_006a805c)(pcVar2);
    if (iVar4 == 0) {
      ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x90);
      return 0;
    }
    if (gost_cipher_list._4_4_ == 0) {
LAB_0061ec1c:
      ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0x9c);
      return 0;
    }
    iVar3 = gost_cipher_list._8_4_;
    piVar6 = (int *)gost_cipher_list;
    iVar7 = gost_cipher_list._4_4_;
    iVar8 = gost_cipher_list._0_4_;
    if (gost_cipher_list._0_4_ != iVar4) {
      do {
        piVar5 = piVar6 + 3;
        iVar7 = piVar6[4];
        if (iVar7 == 0) goto LAB_0061ec1c;
        iVar8 = *piVar5;
        piVar6 = piVar5;
      } while (iVar4 != iVar8);
      goto LAB_0061eba0;
    }
  }
  *piVar9 = iVar8;
  piVar9[1] = 0;
  piVar9[2] = iVar3;
  gost_init(piVar9 + 3,iVar7);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x60);
LAB_0061ead4:
  if (param_2 != 0) {
    gost_key(piVar9 + 3,param_2);
  }
  if (param_3 != 0) {
    uVar1 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(param_1);
    (*(code *)PTR_memcpy_006aabf4)(param_1 + 0x10,param_3,uVar1);
  }
  uVar1 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(param_1);
  (*(code *)PTR_memcpy_006aabf4)(param_1 + 0x20,param_1 + 0x10,uVar1);
  return 1;
}

