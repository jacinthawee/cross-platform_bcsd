
int ssl3_get_cert_verify(int *param_1)

{
  undefined uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined4 uVar10;
  int *unaff_s1;
  int iVar11;
  ushort *puVar12;
  int local_8c;
  undefined4 local_88;
  undefined auStack_84 [23];
  undefined uStack_6d;
  undefined auStack_6c [64];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_84);
  iVar3 = (**(code **)(param_1[2] + 0x30))(param_1,0x21a0,0x21a1,0xffffffff,0x204,&local_8c);
  if (local_8c == 0) goto LAB_004813cc;
  iVar11 = *(int *)(param_1[0x30] + 0x9c);
  if (iVar11 == 0) {
    iVar11 = param_1[0x16];
    if (*(int *)(iVar11 + 0x340) != 0xf) {
      unaff_s1 = (int *)0x0;
      iVar3 = 1;
      *(undefined4 *)(iVar11 + 0x354) = 1;
      goto LAB_00481378;
    }
    unaff_s1 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x88,0xba,"s3_srvr.c",0xb88);
    uVar7 = 10;
    goto LAB_00481444;
  }
  unaff_s1 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)(iVar11);
  uVar4 = (*(code *)PTR_X509_certificate_type_006a914c)(iVar11,unaff_s1);
  iVar11 = param_1[0x16];
  if (*(int *)(iVar11 + 0x340) != 0xf) {
    *(undefined4 *)(iVar11 + 0x354) = 1;
    if ((uVar4 & 0x10) == 0) {
      iVar3 = 1;
      goto LAB_00481378;
    }
    uVar10 = 0xae;
    uVar7 = 0xb7f;
LAB_00481570:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x88,uVar10,"s3_srvr.c",uVar7);
    uVar7 = 10;
    goto LAB_00481444;
  }
  if ((uVar4 & 0x10) == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x88,0xdc,"s3_srvr.c",0xb8f);
    uVar7 = 0x2f;
    goto LAB_00481444;
  }
  if (*(int *)(iVar11 + 0x180) != 0) {
    uVar10 = 0x85;
    uVar7 = 0xb96;
    goto LAB_00481570;
  }
  puVar12 = (ushort *)param_1[0x10];
  if ((iVar3 == 0x40) && (iVar11 = 0, *unaff_s1 - 0x32bU < 2)) {
    uVar4 = 0x40;
LAB_004814c4:
    iVar6 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(unaff_s1);
    if ((((int)uVar4 <= iVar6) && (iVar3 <= iVar6)) && (0 < iVar3)) {
      if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
        iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)
                          (*(undefined4 *)(param_1[0x16] + 0x178),3,0,&local_88);
        if (iVar3 < 1) goto LAB_00481928;
        iVar11 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_84,iVar11,0);
        if ((iVar11 == 0) ||
           (iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,local_88,iVar3), iVar3 == 0)
           ) {
          uVar10 = 6;
          uVar7 = 0xbe8;
          goto LAB_004816f8;
        }
        iVar3 = (*(code *)PTR_EVP_VerifyFinal_006a907c)(auStack_84,puVar12,uVar4,unaff_s1);
        if (0 < iVar3) goto LAB_004817c8;
        uVar10 = 0x7b;
        uVar7 = 0xbf0;
      }
      else {
        iVar3 = *unaff_s1;
        if (iVar3 == 6) {
          iVar3 = (*(code *)PTR_RSA_verify_006a8b68)
                            (0x72,param_1[0x16] + 0x1b4,0x24,puVar12,uVar4,unaff_s1[5]);
          if (iVar3 < 0) {
            uVar10 = 0x76;
            uVar7 = 0xbfe;
          }
          else {
            if (iVar3 != 0) goto LAB_004817c8;
            uVar10 = 0x7a;
            uVar7 = 0xc04;
          }
        }
        else if (iVar3 == 0x74) {
          iVar3 = (*(code *)PTR_DSA_verify_006a8b80)
                            (unaff_s1[1],param_1[0x16] + 0x1c4,0x14,puVar12,uVar4,unaff_s1[5]);
          if (0 < iVar3) {
LAB_004817c8:
            iVar11 = param_1[0x16];
            iVar3 = 1;
            goto LAB_00481378;
          }
          uVar10 = 0x70;
          uVar7 = 0xc14;
        }
        else if (iVar3 == 0x198) {
          iVar3 = (*(code *)PTR_ECDSA_verify_006a8b78)
                            (unaff_s1[1],param_1[0x16] + 0x1c4,0x14,puVar12,uVar4,unaff_s1[5]);
          if (0 < iVar3) goto LAB_004817c8;
          uVar10 = 0x131;
          uVar7 = 0xc25;
        }
        else {
          if (1 < iVar3 - 0x32bU) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x88,0x44,"s3_srvr.c",0xc42);
            uVar7 = 0x2b;
            goto LAB_00481444;
          }
          uVar7 = (*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(unaff_s1,0);
          (*(code *)PTR_EVP_PKEY_verify_init_006a8df0)(uVar7);
          if (uVar4 != 0x40) {
            (*(code *)PTR___fprintf_chk_006aaa8c)
                      (*(undefined4 *)PTR_stderr_006aac00,1,"GOST signature length is %d",uVar4);
          }
          puVar8 = auStack_6c + 0x3f;
          do {
            uVar1 = *(undefined *)puVar12;
            puVar9 = puVar8 + -1;
            puVar12 = (ushort *)((int)puVar12 + 1);
            *puVar8 = uVar1;
            puVar8 = puVar9;
          } while (&uStack_6d != puVar9);
          iVar3 = (*(code *)PTR_EVP_PKEY_verify_006a8df8)
                            (uVar7,auStack_6c,0x40,param_1[0x16] + 0x1b4,0x20);
          (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(uVar7);
          if (0 < iVar3) goto LAB_004817c8;
          uVar10 = 0x131;
          uVar7 = 0xc3c;
        }
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x88,uVar10,"s3_srvr.c",uVar7);
      uVar7 = 0x33;
      goto LAB_00481444;
    }
    uVar10 = 0x109;
    uVar7 = 0xbd1;
  }
  else if (*param_1 >> 8 == 3) {
    iVar11 = 0;
    if (*param_1 < 0x303) goto LAB_004814a0;
    uVar4 = tls12_get_sigid(unaff_s1);
    if (uVar4 == 0xffffffff) {
      uVar10 = 0x44;
      uVar7 = 0xbad;
      goto LAB_004816f8;
    }
    if (uVar4 == *(byte *)((int)puVar12 + 1)) {
      iVar11 = tls12_get_hash(*(undefined *)puVar12);
      if (iVar11 != 0) {
        puVar12 = puVar12 + 1;
        iVar3 = iVar3 + -2;
        goto LAB_004814a0;
      }
      uVar10 = 0x170;
      uVar7 = 0xbbb;
    }
    else {
      uVar10 = 0x172;
      uVar7 = 0xbb4;
    }
  }
  else {
    iVar11 = 0;
LAB_004814a0:
    iVar3 = iVar3 + -2;
    uVar4 = (uint)*puVar12;
    if ((int)uVar4 <= iVar3) {
      puVar12 = puVar12 + 1;
      goto LAB_004814c4;
    }
    uVar10 = 0x9f;
    uVar7 = 0xbc9;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x88,uVar10,"s3_srvr.c",uVar7);
  uVar7 = 0x32;
LAB_00481444:
  while( true ) {
    iVar3 = 0;
    ssl3_send_alert(param_1,2,uVar7);
    iVar11 = param_1[0x16];
LAB_00481378:
    if (*(int *)(iVar11 + 0x178) != 0) {
      (*(code *)PTR_BIO_free_006a7f70)();
      puVar5 = (uint *)param_1[0x16];
      puVar5[0x5e] = 0;
      *puVar5 = *puVar5 & 0xffffffdf;
    }
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_84);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(unaff_s1);
LAB_004813cc:
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00481928:
    uVar10 = 0x44;
    uVar7 = 0xbdd;
LAB_004816f8:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x88,uVar10,"s3_srvr.c",uVar7);
    uVar7 = 0x50;
  }
  return iVar3;
}

