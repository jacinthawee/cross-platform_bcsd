
undefined4
int_rsa_verify(int param_1,int *param_2,int param_3,undefined4 *param_4,int *param_5,uchar *param_6,
              uchar *param_7,RSA *param_8)

{
  undefined *puVar1;
  uchar *flen;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int unaff_s7;
  code *pcVar11;
  uchar *unaff_s8;
  int *local_3c;
  int *local_38;
  uchar *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_3c = param_5;
  flen = (uchar *)RSA_size(param_8);
  local_38 = param_2;
  if (flen != param_7) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,0x77,"rsa_sign.c",0xaf);
    uVar10 = 0;
    goto LAB_00510cd4;
  }
  unaff_s7 = 0x660000;
  unaff_s8 = flen;
  if (param_1 == 0x72) {
    if (param_4 != (undefined4 *)0x0) {
      iVar6 = RSA_public_decrypt((int)flen,param_6,(uchar *)param_4,param_8,1);
      if (iVar6 < 1) {
        uVar10 = 0;
        goto LAB_00510cd4;
      }
      *param_5 = iVar6;
      uVar10 = 1;
      goto LAB_00510cd4;
    }
    unaff_s7 = 0x660000;
    param_7 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(flen,"rsa_sign.c",0xbd);
    if (param_7 == (uchar *)0x0) goto LAB_00510d10;
    if (param_3 == 0x24) {
      iVar6 = RSA_public_decrypt((int)flen,param_6,param_7,param_8,1);
      if (iVar6 < 1) goto LAB_00510e14;
      if ((iVar6 == 0x24) &&
         (iVar6 = (*(code *)PTR_memcmp_006aabd8)(param_7,param_2,0x24), iVar6 == 0)) {
        uVar10 = 1;
        goto LAB_00510c40;
      }
      uVar3 = 0x68;
      uVar10 = 0xde;
    }
    else {
      uVar3 = 0x83;
      uVar10 = 0xc4;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,uVar3,"rsa_sign.c",uVar10);
  }
  else {
    param_7 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(flen,"rsa_sign.c",0xbd);
    if (param_7 == (uchar *)0x0) {
LAB_00510d10:
      unaff_s7 = 0x660000;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,0x41,"rsa_sign.c",0xc0);
      uVar10 = 0;
      goto LAB_00510cd4;
    }
    param_6 = (uchar *)RSA_public_decrypt((int)flen,param_6,param_7,param_8,1);
    pcVar11 = (code *)PTR_d2i_X509_SIG_006a985c;
    if (0 < (int)param_6) {
      if (param_1 != 0x5f) {
        uVar10 = 0;
        goto LAB_00510bdc;
      }
      uVar10 = 0;
      if (param_6 != &DAT_00000012) goto LAB_00510bdc;
      if (*param_7 != '\x04') goto LAB_00510bdc;
      if (param_7[1] != '\x10') goto LAB_00510bdc;
      if (param_4 == (undefined4 *)0x0) goto LAB_00511068;
      uVar10 = 1;
      uVar9 = *(undefined4 *)(param_7 + 6);
      uVar8 = *(undefined4 *)(param_7 + 10);
      uVar3 = *(undefined4 *)(param_7 + 0xe);
      *param_4 = *(undefined4 *)(param_7 + 2);
      param_4[1] = uVar9;
      param_4[2] = uVar8;
      param_4[3] = uVar3;
      *param_5 = 0x10;
      goto LAB_00510bdc;
    }
  }
LAB_00510e14:
  unaff_s7 = 0x660000;
  uVar10 = 0;
LAB_00510c40:
  do {
    do {
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(param_7,flen);
      (*(code *)PTR_CRYPTO_free_006a7f88)(param_7);
      unaff_s8 = flen;
LAB_00510cd4:
      if (local_2c == *(int *)puVar1) {
        return uVar10;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      flen = unaff_s8;
LAB_00511068:
      iVar6 = (*(code *)PTR_memcmp_006aabd8)(local_38,param_7 + 2,0x10);
      if (iVar6 == 0) {
        uVar10 = 1;
        pcVar11 = (code *)PTR_d2i_X509_SIG_006a985c;
      }
      else {
        uVar10 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,0x68,unaff_s7 + 0x7650,0xd6);
        pcVar11 = (code *)PTR_d2i_X509_SIG_006a985c;
      }
LAB_00510bdc:
      local_30 = param_7;
      piVar2 = (int *)(*pcVar11)(0,&local_30,param_6);
    } while (piVar2 == (int *)0x0);
    param_6 = param_7 + (int)param_6;
    if (local_30 == param_6) {
      puVar4 = (undefined4 *)*piVar2;
      if (puVar4[1] != 0) {
        iVar6 = (*(code *)PTR_ASN1_TYPE_get_006a85b0)();
        if (iVar6 != 5) {
          uVar8 = 0x68;
          uVar3 = 0xf2;
          goto LAB_00510c1c;
        }
        puVar4 = (undefined4 *)*piVar2;
      }
      iVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar4);
      if (param_1 != iVar6) {
        if (param_1 == 4) {
          if (iVar6 == 8) goto LAB_00510f30;
        }
        else if ((param_1 == 3) && (iVar6 == 7)) {
LAB_00510f30:
          (*(code *)PTR_fwrite_006aab7c)
                    ("signature has problems, re-make with post SSLeay045\n",1,0x34,
                     *(undefined4 *)PTR_stderr_006aac00);
          goto LAB_00510f5c;
        }
        uVar8 = 100;
        uVar3 = 0x10d;
        goto LAB_00510c1c;
      }
LAB_00510f5c:
      if (param_4 == (undefined4 *)0x0) {
        if ((param_3 != *(int *)piVar2[1]) ||
           (iVar6 = (*(code *)PTR_memcmp_006aabd8)(local_38,((int *)piVar2[1])[2],param_3),
           iVar6 != 0)) {
          uVar8 = 0x68;
          uVar3 = 0x123;
          goto LAB_00510c1c;
        }
        uVar10 = 1;
        local_3c = piVar2;
      }
      else {
        uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(param_1);
        iVar6 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar3);
        local_38 = piVar2;
        if (iVar6 == 0) {
          piVar7 = (int *)piVar2[1];
          iVar6 = *piVar7;
        }
        else {
          iVar5 = (*(code *)PTR_EVP_MD_size_006a8f2c)(iVar6);
          piVar7 = (int *)piVar2[1];
          iVar6 = *piVar7;
          if (iVar5 != iVar6) {
            uVar8 = 0x8f;
            uVar3 = 0x117;
            goto LAB_00510c1c;
          }
        }
        uVar10 = 1;
        (*(code *)PTR_memcpy_006aabf4)(param_4,piVar7[2],iVar6);
        *local_3c = *(int *)piVar2[1];
      }
    }
    else {
      uVar8 = 0x68;
      uVar3 = 0xe9;
LAB_00510c1c:
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,uVar8,unaff_s7 + 0x7650,uVar3);
      local_3c = piVar2;
    }
    (*(code *)PTR_X509_SIG_free_006a8d98)(piVar2);
  } while( true );
}

