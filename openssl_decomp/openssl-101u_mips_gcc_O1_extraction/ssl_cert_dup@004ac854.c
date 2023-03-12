
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
  void **ppvVar11;
  
  ppvVar2 = (void **)CRYPTO_malloc(0x94,"ssl_cert.c",0xc9);
  if (ppvVar2 == (void **)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xdd,0x41,"ssl_cert.c",0xcb);
    ppvVar2 = (void **)0x0;
  }
  else {
    (*(code *)PTR_memset_006a99f4)(ppvVar2,0,0x94);
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
    ppvVar2[0x24] = (void *)0x1;
    *ppvVar2 = ppvVar2 + (iVar3 - (int)ppvVar10 >> 2) + 0xc;
    if (iVar5 != 0) {
      (*(code *)PTR_RSA_up_ref_006a7f98)();
      ppvVar2[6] = (void *)param_1[6];
    }
    iVar3 = param_1[8];
    ppvVar2[7] = (void *)param_1[7];
    if (iVar3 != 0) {
      pvVar4 = (void *)(*(code *)PTR_DHparams_dup_006a7f8c)();
      ppvVar2[8] = pvVar4;
      if (pvVar4 == (void *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xdd,5,"ssl_cert.c",0xea);
        goto LAB_004acafc;
      }
      iVar3 = param_1[8];
      if (*(int *)(iVar3 + 0x18) != 0) {
        iVar5 = (*(code *)PTR_BN_dup_006a8218)();
        if (iVar5 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xdd,3,"ssl_cert.c",0xf0);
          goto LAB_004acafc;
        }
        iVar3 = param_1[8];
        *(int *)((int)ppvVar2[8] + 0x18) = iVar5;
      }
      if (*(int *)(iVar3 + 0x14) != 0) {
        iVar3 = (*(code *)PTR_BN_dup_006a8218)();
        if (iVar3 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xdd,3,"ssl_cert.c",0xf8);
          goto LAB_004acafc;
        }
        *(int *)((int)ppvVar2[8] + 0x14) = iVar3;
      }
    }
    iVar3 = param_1[10];
    ppvVar2[9] = (void *)param_1[9];
    if (iVar3 != 0) {
      pvVar4 = (void *)(*(code *)PTR_EC_KEY_dup_006a7f74)();
      ppvVar2[10] = pvVar4;
      if (pvVar4 == (void *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xdd,0x10,"ssl_cert.c",0x105);
LAB_004acafc:
        if (ppvVar2[6] != (void *)0x0) {
          (*(code *)PTR_RSA_free_006a7600)();
        }
        if (ppvVar2[8] != (void *)0x0) {
          (*(code *)PTR_DH_free_006a7508)();
        }
        ppvVar10 = ppvVar2 + 0xc;
        if (ppvVar2[10] != (void *)0x0) {
          (*(code *)PTR_EC_KEY_free_006a71d4)();
        }
        do {
          if (*ppvVar10 != (void *)0x0) {
            (*(code *)PTR_X509_free_006a6e90)();
          }
          ppvVar11 = ppvVar10 + 1;
          ppvVar10 = ppvVar10 + 3;
          if (*ppvVar11 != (void *)0x0) {
            (*(code *)PTR_EVP_PKEY_free_006a6e78)();
          }
        } while (ppvVar10 != ppvVar2 + 0x24);
        return (void *)0x0;
      }
    }
    ppvVar11 = ppvVar2 + 0xd;
    ppvVar2[0xb] = (void *)param_1[0xb];
    do {
      pvVar4 = *ppvVar10;
      if (pvVar4 != (void *)0x0) {
        ppvVar11[-1] = pvVar4;
        CRYPTO_add_lock((int *)((int)pvVar4 + 0x10),1,3,"ssl_cert.c",0x10f);
      }
      pvVar4 = ppvVar10[1];
      ppvVar10 = ppvVar10 + 3;
      if (pvVar4 != (void *)0x0) {
        *ppvVar11 = pvVar4;
        CRYPTO_add_lock((int *)((int)pvVar4 + 8),1,10,"ssl_cert.c",0x115);
      }
      ppvVar11 = ppvVar11 + 3;
    } while (ppvVar10 != (void **)(param_1 + 0x24));
    pvVar4 = (void *)(*(code *)PTR_EVP_sha1_006a75d0)();
    puVar1 = PTR_EVP_sha1_006a75d0;
    ppvVar2[0x14] = pvVar4;
    pvVar4 = (void *)(*(code *)puVar1)();
    puVar1 = PTR_EVP_sha1_006a75d0;
    ppvVar2[0x11] = pvVar4;
    pvVar4 = (void *)(*(code *)puVar1)();
    puVar1 = PTR_EVP_sha1_006a75d0;
    ppvVar2[0xe] = pvVar4;
    pvVar4 = (void *)(*(code *)puVar1)();
    ppvVar2[0x1d] = pvVar4;
  }
  return ppvVar2;
}

