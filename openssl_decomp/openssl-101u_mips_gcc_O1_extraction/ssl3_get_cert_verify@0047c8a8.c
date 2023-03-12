
int ssl3_get_cert_verify(int *param_1)

{
  undefined uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int *unaff_s4;
  ushort *unaff_s5;
  uint unaff_s6;
  int iVar11;
  int local_8c;
  undefined4 local_88;
  undefined auStack_84 [23];
  undefined uStack_6d;
  undefined auStack_6c [64];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_84);
  if (*(int *)(param_1[0x30] + 0x9c) == 0) {
    iVar3 = 1;
    unaff_s4 = (int *)0x0;
    goto LAB_0047ca9c;
  }
  iVar3 = (**(code **)(param_1[2] + 0x30))(param_1,0x21a0,0x21a1,0xf,0x4000,&local_8c);
  if (local_8c == 0) goto LAB_0047c94c;
  uVar9 = *(undefined4 *)(param_1[0x30] + 0x9c);
  unaff_s4 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(uVar9);
  uVar4 = (*(code *)PTR_X509_certificate_type_006a7fd0)(uVar9,unaff_s4);
  if ((uVar4 & 0x10) == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x88,0xdc,"s3_srvr.c",3000);
    uVar9 = 0x2f;
    goto LAB_0047cb24;
  }
  unaff_s5 = (ushort *)param_1[0x10];
  if ((iVar3 == 0x40) && (iVar11 = 0, *unaff_s4 - 0x32bU < 2)) {
    unaff_s6 = 0x40;
LAB_0047ca00:
    iVar5 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(unaff_s4);
    if ((((int)unaff_s6 <= iVar5) && (iVar3 <= iVar5)) && (0 < iVar3)) {
      if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
        iVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)
                          (*(undefined4 *)(param_1[0x16] + 0x178),3,0,&local_88);
        if (iVar3 < 1) {
          uVar10 = 0x44;
          uVar9 = 0xbf7;
        }
        else {
          iVar11 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_84,iVar11,0);
          if ((iVar11 != 0) &&
             (iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_84,local_88,iVar3),
             iVar3 != 0)) goto LAB_0047cf04;
          uVar10 = 6;
          uVar9 = 0xc01;
        }
      }
      else {
        iVar3 = *unaff_s4;
        if (iVar3 == 6) {
          iVar3 = (*(code *)PTR_RSA_verify_006a7a7c)
                            (0x72,param_1[0x16] + 0x1b4,0x24,unaff_s5,unaff_s6,unaff_s4[5]);
          if (iVar3 < 0) {
            uVar10 = 0x76;
            uVar9 = 0xc13;
            goto LAB_0047cd54;
          }
          if (iVar3 != 0) goto LAB_0047cd38;
          uVar10 = 0x7a;
          uVar9 = 0xc18;
          goto LAB_0047cd54;
        }
        if (iVar3 == 0x74) {
          iVar3 = (*(code *)PTR_DSA_verify_006a7a94)
                            (unaff_s4[1],param_1[0x16] + 0x1c4,0x14,unaff_s5,unaff_s6,unaff_s4[5]);
          if (0 < iVar3) goto LAB_0047cd38;
          uVar10 = 0x70;
          uVar9 = 0xc25;
          goto LAB_0047cd54;
        }
        if (iVar3 == 0x198) {
          iVar3 = (*(code *)PTR_ECDSA_verify_006a7a8c)
                            (unaff_s4[1],param_1[0x16] + 0x1c4,0x14,unaff_s5,unaff_s6,unaff_s4[5]);
          if (0 < iVar3) goto LAB_0047cd38;
          uVar10 = 0x131;
          uVar9 = 0xc32;
          goto LAB_0047cd54;
        }
        if (1 < iVar3 - 0x32bU) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x88,0x44,"s3_srvr.c",0xc56);
          uVar9 = 0x2b;
          goto LAB_0047cb24;
        }
        iVar3 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(unaff_s4,0);
        if (iVar3 == 0) {
          uVar10 = 0x41;
          uVar9 = 0xc3e;
        }
        else {
          iVar11 = (*(code *)PTR_EVP_PKEY_verify_init_006a7d00)(iVar3);
          if (0 < iVar11) {
            if (unaff_s6 != 0x40) {
              (*(code *)PTR___fprintf_chk_006a9980)
                        (*(undefined4 *)PTR_stderr_006a9af8,1,"GOST signature length is %d",unaff_s6
                        );
            }
            puVar7 = auStack_6c + 0x3f;
            do {
              uVar1 = *(undefined *)unaff_s5;
              puVar8 = puVar7 + -1;
              unaff_s5 = (ushort *)((int)unaff_s5 + 1);
              *puVar7 = uVar1;
              puVar7 = puVar8;
            } while (&uStack_6d != puVar8);
            iVar11 = (*(code *)PTR_EVP_PKEY_verify_006a7d08)
                               (iVar3,auStack_6c,0x40,param_1[0x16] + 0x1b4,0x20);
            (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar3);
            if (0 < iVar11) goto LAB_0047cd38;
            uVar10 = 0x131;
            uVar9 = 0xc52;
            goto LAB_0047cd54;
          }
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar3);
          uVar10 = 0x44;
          uVar9 = 0xc44;
        }
      }
LAB_0047cc64:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x88,uVar10,"s3_srvr.c",uVar9);
      uVar9 = 0x50;
      goto LAB_0047cb24;
    }
    uVar10 = 0x109;
    uVar9 = 0xbed;
  }
  else {
    if (*param_1 >> 8 == 3) {
      iVar11 = 0;
      if (*param_1 < 0x303) goto LAB_0047c9e0;
      uVar4 = tls12_get_sigid(unaff_s4);
      if (uVar4 != 0xffffffff) {
        if (uVar4 == *(byte *)((int)unaff_s5 + 1)) {
          iVar11 = tls12_get_hash(*(undefined *)unaff_s5);
          if (iVar11 != 0) {
            unaff_s5 = unaff_s5 + 1;
            iVar3 = iVar3 + -2;
            goto LAB_0047c9e0;
          }
          uVar10 = 0x170;
          uVar9 = 0xbd9;
        }
        else {
          uVar10 = 0x172;
          uVar9 = 0xbd3;
        }
        goto LAB_0047cb9c;
      }
      uVar10 = 0x44;
      uVar9 = 0xbcc;
      goto LAB_0047cc64;
    }
    iVar11 = 0;
LAB_0047c9e0:
    iVar3 = iVar3 + -2;
    unaff_s6 = (uint)*unaff_s5;
    unaff_s5 = unaff_s5 + 1;
    if ((int)unaff_s6 <= iVar3) goto LAB_0047ca00;
    uVar10 = 0x9f;
    uVar9 = 0xbe6;
  }
LAB_0047cb9c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x88,uVar10,"s3_srvr.c",uVar9);
  uVar9 = 0x32;
LAB_0047cb24:
  do {
    iVar3 = 0;
    ssl3_send_alert(param_1,2,uVar9);
    param_1[0xd] = 5;
LAB_0047ca9c:
    while( true ) {
      if (*(int *)(param_1[0x16] + 0x178) != 0) {
        (*(code *)PTR_BIO_free_006a6e70)();
        puVar6 = (uint *)param_1[0x16];
        puVar6[0x5e] = 0;
        *puVar6 = *puVar6 & 0xffffffdf;
      }
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_84);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(unaff_s4);
LAB_0047c94c:
      if (local_2c == *(int *)puVar2) {
        return iVar3;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0047cf04:
      iVar3 = (*(code *)PTR_EVP_VerifyFinal_006a7fdc)(auStack_84,unaff_s5,unaff_s6,unaff_s4);
      if (iVar3 < 1) break;
LAB_0047cd38:
      iVar3 = 1;
    }
    uVar10 = 0x7b;
    uVar9 = 0xc08;
LAB_0047cd54:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x88,uVar10,"s3_srvr.c",uVar9);
    uVar9 = 0x33;
  } while( true );
}

