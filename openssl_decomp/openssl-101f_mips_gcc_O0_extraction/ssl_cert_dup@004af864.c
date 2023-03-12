
void * ssl_cert_dup(int *param_1)

{
  undefined *puVar1;
  void **ppvVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  void **ppvVar10;
  uint uVar11;
  void **ppvVar12;
  
  ppvVar2 = (void **)CRYPTO_malloc(0x94,"ssl_cert.c",0xc9);
  if (ppvVar2 == (void **)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xdd,0x41,"ssl_cert.c",0xcc);
    ppvVar2 = (void **)0x0;
  }
  else {
    (*(code *)PTR_memset_006aab00)(ppvVar2,0,0x94);
    iVar3 = *param_1;
    ppvVar10 = (void **)(param_1 + 0xc);
    iVar9 = param_1[2];
    iVar8 = param_1[3];
    iVar7 = param_1[4];
    iVar6 = param_1[5];
    iVar5 = param_1[6];
    ppvVar2[1] = (void *)param_1[1];
    ppvVar2[2] = (void *)iVar9;
    ppvVar2[3] = (void *)iVar8;
    ppvVar2[4] = (void *)iVar7;
    ppvVar2[5] = (void *)iVar6;
    *ppvVar2 = ppvVar2 + (iVar3 - (int)ppvVar10 >> 2) + 0xc;
    if (iVar5 != 0) {
      (*(code *)PTR_RSA_up_ref_006a9120)();
      ppvVar2[6] = (void *)param_1[6];
    }
    iVar3 = param_1[8];
    ppvVar2[7] = (void *)param_1[7];
    if (iVar3 != 0) {
      pvVar4 = (void *)(*(code *)PTR_DHparams_dup_006a90f8)();
      ppvVar2[8] = pvVar4;
      if (pvVar4 == (void *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xdd,5,"ssl_cert.c",0xeb);
        goto LAB_004afb5c;
      }
      iVar3 = param_1[8];
      if (*(int *)(iVar3 + 0x18) != 0) {
        iVar5 = (*(code *)PTR_BN_dup_006a9100)();
        if (iVar5 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xdd,3,"ssl_cert.c",0xf3);
          goto LAB_004afb5c;
        }
        iVar3 = param_1[8];
        *(int *)((int)ppvVar2[8] + 0x18) = iVar5;
      }
      if (*(int *)(iVar3 + 0x14) != 0) {
        iVar3 = (*(code *)PTR_BN_dup_006a9100)();
        if (iVar3 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xdd,3,"ssl_cert.c",0xfd);
          goto LAB_004afb5c;
        }
        *(int *)((int)ppvVar2[8] + 0x14) = iVar3;
      }
    }
    iVar3 = param_1[10];
    ppvVar2[9] = (void *)param_1[9];
    if (iVar3 != 0) {
      pvVar4 = (void *)(*(code *)PTR_EC_KEY_dup_006a9108)();
      ppvVar2[10] = pvVar4;
      if (pvVar4 == (void *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xdd,0x10,"ssl_cert.c",0x10c);
LAB_004afb5c:
        if (ppvVar2[6] != (void *)0x0) {
          (*(code *)PTR_RSA_free_006a86f0)();
        }
        if (ppvVar2[8] != (void *)0x0) {
          (*(code *)PTR_DH_free_006a8604)();
        }
        ppvVar10 = ppvVar2 + 0xc;
        if (ppvVar2[10] != (void *)0x0) {
          (*(code *)PTR_EC_KEY_free_006a82d8)();
        }
        do {
          if (*ppvVar10 != (void *)0x0) {
            (*(code *)PTR_X509_free_006a7f90)();
          }
          ppvVar12 = ppvVar10 + 1;
          ppvVar10 = ppvVar10 + 3;
          if (*ppvVar12 != (void *)0x0) {
            (*(code *)PTR_EVP_PKEY_free_006a7f78)();
          }
        } while (ppvVar10 != ppvVar2 + 0x24);
        return (void *)0x0;
      }
    }
    ppvVar12 = ppvVar2 + 0xd;
    uVar11 = 0;
    ppvVar2[0xb] = (void *)param_1[0xb];
LAB_004afa28:
    do {
      pvVar4 = *ppvVar10;
      if (pvVar4 != (void *)0x0) {
        ppvVar12[-1] = pvVar4;
        CRYPTO_add_lock((int *)((int)pvVar4 + 0x10),1,3,"ssl_cert.c",0x119);
      }
      pvVar4 = ppvVar10[1];
      ppvVar10 = ppvVar10 + 3;
      if (pvVar4 != (void *)0x0) {
        *ppvVar12 = pvVar4;
        CRYPTO_add_lock((int *)((int)pvVar4 + 8),1,10,"ssl_cert.c",0x120);
        if (5 < uVar11) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xdd,0x112,"ssl_cert.c",0x13c);
          uVar11 = uVar11 + 1;
          ppvVar12 = ppvVar12 + 3;
          if (uVar11 == 8) break;
          goto LAB_004afa28;
        }
      }
      uVar11 = uVar11 + 1;
      ppvVar12 = ppvVar12 + 3;
    } while (uVar11 != 8);
    puVar1 = PTR_EVP_sha1_006a86c4;
    ppvVar2[0x24] = (void *)0x1;
    pvVar4 = (void *)(*(code *)puVar1)();
    puVar1 = PTR_EVP_sha1_006a86c4;
    ppvVar2[0x14] = pvVar4;
    pvVar4 = (void *)(*(code *)puVar1)();
    puVar1 = PTR_EVP_sha1_006a86c4;
    ppvVar2[0x11] = pvVar4;
    pvVar4 = (void *)(*(code *)puVar1)();
    puVar1 = PTR_EVP_sha1_006a86c4;
    ppvVar2[0xe] = pvVar4;
    pvVar4 = (void *)(*(code *)puVar1)();
    ppvVar2[0x1d] = pvVar4;
  }
  return ppvVar2;
}

