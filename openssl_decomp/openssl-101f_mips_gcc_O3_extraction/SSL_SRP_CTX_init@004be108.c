
undefined4 SSL_SRP_CTX_init(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar7 = *(int *)(param_1 + 0xe4);
  if (iVar7 == 0) {
    return 0;
  }
  uVar6 = *(undefined4 *)(iVar7 + 0x168);
  uVar5 = *(undefined4 *)(iVar7 + 0x16c);
  uVar4 = *(undefined4 *)(iVar7 + 0x170);
  uVar2 = *(undefined4 *)(iVar7 + 0x198);
  uVar1 = *(undefined4 *)(iVar7 + 0x19c);
  iVar3 = *(int *)(iVar7 + 0x178);
  *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(iVar7 + 0x164);
  *(undefined4 *)(param_1 + 0x198) = uVar6;
  *(undefined4 *)(param_1 + 0x19c) = uVar5;
  *(undefined4 *)(param_1 + 0x1a0) = uVar4;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = uVar2;
  *(undefined4 *)(param_1 + 0x1cc) = uVar1;
  if (iVar3 == 0) {
LAB_004be1a8:
    if (*(int *)(iVar7 + 0x17c) != 0) {
      iVar3 = (*(code *)PTR_BN_dup_006a9100)();
      *(int *)(param_1 + 0x1ac) = iVar3;
      if (iVar3 == 0) goto LAB_004be2c8;
    }
    if (*(int *)(iVar7 + 0x180) != 0) {
      iVar3 = (*(code *)PTR_BN_dup_006a9100)();
      *(int *)(param_1 + 0x1b0) = iVar3;
      if (iVar3 == 0) goto LAB_004be2c8;
    }
    if (*(int *)(iVar7 + 0x184) != 0) {
      iVar3 = (*(code *)PTR_BN_dup_006a9100)();
      *(int *)(param_1 + 0x1b4) = iVar3;
      if (iVar3 == 0) goto LAB_004be2c8;
    }
    if (*(int *)(iVar7 + 0x188) != 0) {
      iVar3 = (*(code *)PTR_BN_dup_006a9100)();
      *(int *)(param_1 + 0x1b8) = iVar3;
      if (iVar3 == 0) goto LAB_004be2c8;
    }
    if (*(int *)(iVar7 + 0x18c) != 0) {
      iVar3 = (*(code *)PTR_BN_dup_006a9100)();
      *(int *)(param_1 + 0x1bc) = iVar3;
      if (iVar3 == 0) goto LAB_004be2c8;
    }
    if (*(int *)(iVar7 + 0x194) != 0) {
      iVar3 = (*(code *)PTR_BN_dup_006a9100)();
      *(int *)(param_1 + 0x1c4) = iVar3;
      if (iVar3 == 0) goto LAB_004be2c8;
    }
    if (*(int *)(iVar7 + 400) != 0) {
      iVar3 = (*(code *)PTR_BN_dup_006a9100)();
      *(int *)(param_1 + 0x1c0) = iVar3;
      if (iVar3 == 0) goto LAB_004be2c8;
    }
    if (*(int *)(iVar7 + 0x174) != 0) {
      iVar3 = (*(code *)PTR_BUF_strdup_006a80dc)();
      *(int *)(param_1 + 0x1a4) = iVar3;
      if (iVar3 == 0) {
        uVar2 = 0x44;
        uVar1 = 0xb3;
        goto LAB_004be2dc;
      }
    }
    *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(iVar7 + 0x1a0);
    return 1;
  }
  iVar3 = (*(code *)PTR_BN_dup_006a9100)();
  *(int *)(param_1 + 0x1a8) = iVar3;
  if (iVar3 != 0) goto LAB_004be1a8;
LAB_004be2c8:
  uVar2 = 3;
  uVar1 = 0xad;
LAB_004be2dc:
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x139,uVar2,"tls_srp.c",uVar1);
  CRYPTO_free(*(void **)(param_1 + 0x1a4));
  (*(code *)PTR_BN_free_006a811c)(*(undefined4 *)(param_1 + 0x1a8));
  (*(code *)PTR_BN_free_006a811c)(*(undefined4 *)(param_1 + 0x1ac));
  (*(code *)PTR_BN_free_006a811c)(*(undefined4 *)(param_1 + 0x1b0));
  (*(code *)PTR_BN_free_006a811c)(*(undefined4 *)(param_1 + 0x1b4));
  (*(code *)PTR_BN_free_006a811c)(*(undefined4 *)(param_1 + 0x1b8));
  (*(code *)PTR_BN_free_006a811c)(*(undefined4 *)(param_1 + 0x1bc));
  (*(code *)PTR_BN_free_006a811c)(*(undefined4 *)(param_1 + 0x1c0));
  (*(code *)PTR_BN_free_006a811c)(*(undefined4 *)(param_1 + 0x1c4));
  return 0;
}

