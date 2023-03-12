
int PEM_read_bio(BIO *bp,char **name,char **header,uchar **data,long *len)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int local_194;
  int local_190;
  undefined auStack_18c [96];
  char local_12c [9];
  char acStack_123 [245];
  undefined local_2e;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_190 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_BUF_MEM_new_006a749c)();
  iVar4 = (*(code *)PTR_BUF_MEM_new_006a749c)();
  iVar5 = (*(code *)PTR_BUF_MEM_new_006a749c)();
  if (((iVar3 != 0) && (iVar4 != 0)) && (iVar5 != 0)) {
    local_2e = 0;
    do {
      do {
        iVar6 = (*(code *)PTR_BIO_gets_006a74d4)(bp,local_12c,0xfe);
        if (iVar6 < 1) {
          uVar10 = 0x6c;
          uVar11 = 0x2b8;
          goto LAB_0056ca50;
        }
        pcVar9 = local_12c + iVar6;
        do {
          if (' ' < *pcVar9) break;
          iVar6 = iVar6 + -1;
          pcVar9 = pcVar9 + -1;
        } while (iVar6 != -1);
        local_12c[iVar6 + 2] = '\0';
        local_12c[iVar6 + 1] = '\n';
        iVar6 = (*(code *)PTR_strncmp_006a9970)(local_12c,"-----BEGIN ",0xb);
      } while (iVar6 != 0);
      iVar6 = (*(code *)PTR_strlen_006a9a24)(acStack_123 + 2);
      iVar7 = (*(code *)PTR_strncmp_006a9970)(local_12c + iVar6 + 5,"-----\n",6);
    } while (iVar7 != 0);
    iVar7 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar3,iVar6 + 9);
    if (iVar7 == 0) {
      uVar10 = 0x41;
      uVar11 = 0x2c7;
      goto LAB_0056ca50;
    }
    (*(code *)PTR_memcpy_006a9aec)(*(undefined4 *)(iVar3 + 4),acStack_123 + 2,iVar6 + -6);
    puVar1 = PTR_BUF_MEM_grow_006a74a0;
    *(undefined *)(*(int *)(iVar3 + 4) + iVar6 + -6) = 0;
    iVar6 = (*(code *)puVar1)(iVar4,0x100);
    if (iVar6 == 0) {
      uVar10 = 0x41;
      uVar11 = 0x2d1;
      goto LAB_0056ca50;
    }
    **(undefined **)(iVar4 + 4) = 0;
    iVar6 = 0;
    while (iVar7 = (*(code *)PTR_BIO_gets_006a74d4)(bp,local_12c,0xfe), 0 < iVar7) {
      pcVar9 = local_12c + iVar7;
      do {
        if (' ' < *pcVar9) break;
        iVar7 = iVar7 + -1;
        pcVar9 = pcVar9 + -1;
      } while (iVar7 != -1);
      local_12c[iVar7 + 1] = '\n';
      local_12c[iVar7 + 2] = '\0';
      iVar12 = iVar6 + iVar7 + 2;
      if (local_12c[0] == '\n') break;
      iVar8 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar4,iVar12 + 9);
      if (iVar8 == 0) {
        uVar10 = 0x41;
        uVar11 = 0x2e2;
        goto LAB_0056ca50;
      }
      iVar8 = (*(code *)PTR_strncmp_006a9970)(local_12c,"-----END ",9);
      if (iVar8 == 0) {
        local_190 = 0;
        iVar7 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar5,0x400);
        if (iVar7 == 0) goto LAB_0056cb6c;
        **(undefined **)(iVar5 + 4) = 0;
        iVar7 = iVar5;
        iVar5 = iVar4;
        local_190 = iVar6;
        goto LAB_0056cce0;
      }
      (*(code *)PTR_memcpy_006a9aec)(*(int *)(iVar4 + 4) + iVar6,local_12c,iVar7 + 2);
      *(undefined *)(*(int *)(iVar4 + 4) + iVar12) = 0;
      iVar6 = iVar12;
    }
    local_190 = 0;
    iVar6 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar5,0x400);
    if (iVar6 == 0) {
LAB_0056cb6c:
      uVar10 = 0x41;
      uVar11 = 0x2f0;
      goto LAB_0056ca50;
    }
    **(undefined **)(iVar5 + 4) = 0;
    do {
      iVar6 = (*(code *)PTR_BIO_gets_006a74d4)(bp,local_12c,0xfe);
      iVar7 = iVar4;
      if (iVar6 < 1) goto LAB_0056cce0;
      pcVar9 = local_12c + iVar6;
      do {
        if (' ' < *pcVar9) {
          iVar12 = iVar6 + 2;
          local_12c[iVar6 + 1] = '\n';
          local_12c[iVar6 + 2] = '\0';
          iVar6 = (*(code *)PTR_strncmp_006a9970)(local_12c,"-----END ",9);
          if (iVar6 == 0) goto LAB_0056cef0;
          if (iVar12 < 0x42) goto LAB_0056cc24;
          goto LAB_0056ce70;
        }
        iVar6 = iVar6 + -1;
        pcVar9 = pcVar9 + -1;
      } while (iVar6 != -1);
      local_12c[1] = 0;
      local_12c[0] = '\n';
      iVar6 = (*(code *)PTR_strncmp_006a9970)(local_12c,"-----END ",9);
      if (iVar6 == 0) {
LAB_0056cef0:
        uVar11 = *(undefined4 *)(iVar3 + 4);
        iVar6 = (*(code *)PTR_strlen_006a9a24)(uVar11);
        goto LAB_0056cd18;
      }
      iVar12 = 1;
LAB_0056cc24:
      iVar6 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar5,iVar12 + local_190 + 9);
      if (iVar6 == 0) {
        uVar10 = 0x41;
        uVar11 = 0x306;
        goto LAB_0056ca50;
      }
      (*(code *)PTR_memcpy_006a9aec)(*(int *)(iVar5 + 4) + local_190,local_12c,iVar12);
      *(undefined *)(*(int *)(iVar5 + 4) + iVar12 + local_190) = 0;
      local_190 = local_190 + iVar12;
    } while (iVar12 == 0x41);
    local_12c[0] = '\0';
    iVar4 = (*(code *)PTR_BIO_gets_006a74d4)(bp,local_12c,0xfe);
    if (0 < iVar4) {
      pcVar9 = local_12c + iVar4;
      do {
        iVar6 = iVar4 + -1;
        if (' ' < *pcVar9) break;
        pcVar9 = pcVar9 + -1;
        iVar4 = iVar6;
      } while (iVar6 != -1);
      local_12c[iVar4 + 2] = '\0';
      local_12c[iVar4 + 1] = '\n';
    }
LAB_0056cce0:
    uVar11 = *(undefined4 *)(iVar3 + 4);
    iVar6 = (*(code *)PTR_strlen_006a9a24)(uVar11);
    iVar12 = (*(code *)PTR_strncmp_006a9970)(local_12c,"-----END ",9);
    iVar4 = iVar7;
    if (iVar12 == 0) {
LAB_0056cd18:
      iVar7 = (*(code *)PTR_strncmp_006a9970)(uVar11,acStack_123,iVar6);
      if ((iVar7 == 0) &&
         (iVar6 = (*(code *)PTR_strncmp_006a9970)(local_12c + iVar6 + 9,"-----\n",6), iVar6 == 0)) {
        (*(code *)PTR_EVP_DecodeInit_006a8ae8)(auStack_18c);
        iVar6 = (*(code *)PTR_EVP_DecodeUpdate_006a8af0)
                          (auStack_18c,*(undefined4 *)(iVar5 + 4),&local_190,
                           *(undefined4 *)(iVar5 + 4),local_190);
        if (iVar6 < 0) {
          uVar10 = 100;
          uVar11 = 0x32d;
          goto LAB_0056ca50;
        }
        iVar6 = (*(code *)PTR_EVP_DecodeFinal_006a8e38)
                          (auStack_18c,*(int *)(iVar5 + 4) + local_190,&local_194);
        puVar1 = PTR_CRYPTO_free_006a6e88;
        if (iVar6 < 0) goto LAB_0056cf30;
        local_190 = local_190 + local_194;
        if (local_190 == 0) goto LAB_0056ca64;
        *name = *(char **)(iVar3 + 4);
        *header = *(char **)(iVar4 + 4);
        *data = *(uchar **)(iVar5 + 4);
        *len = local_190;
        (*(code *)puVar1)(iVar3);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
        iVar6 = 1;
        goto LAB_0056ca98;
      }
    }
LAB_0056ce70:
    uVar10 = 0x66;
    uVar11 = 0x324;
    goto LAB_0056ca50;
  }
  (*(code *)PTR_BUF_MEM_free_006a7494)(iVar3);
  (*(code *)PTR_BUF_MEM_free_006a7494)(iVar4);
  (*(code *)PTR_BUF_MEM_free_006a7494)(iVar5);
  (*(code *)PTR_ERR_put_error_006a7f34)(9,0x6d,0x41,"pem_lib.c",0x2af);
  iVar6 = 0;
LAB_0056ca98:
  while (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0056cf30:
    uVar10 = 100;
    uVar11 = 0x332;
LAB_0056ca50:
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x6d,uVar10,"pem_lib.c",uVar11);
LAB_0056ca64:
    (*(code *)PTR_BUF_MEM_free_006a7494)(iVar3);
    (*(code *)PTR_BUF_MEM_free_006a7494)(iVar4);
    (*(code *)PTR_BUF_MEM_free_006a7494)(iVar5);
    iVar6 = 0;
  }
  return iVar6;
}

