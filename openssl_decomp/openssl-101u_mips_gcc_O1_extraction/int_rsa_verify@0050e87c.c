
undefined4
int_rsa_verify(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,int *param_5,
              int *param_6,uchar *param_7,RSA *param_8)

{
  undefined *puVar1;
  uchar *flen;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 uVar10;
  int unaff_s7;
  uchar *unaff_s8;
  uchar *local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  flen = (uchar *)RSA_size(param_8);
  if (flen != param_7) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,0x77,"rsa_sign.c",0xba);
    uVar10 = 0;
    goto LAB_0050ea60;
  }
  unaff_s7 = 0x660000;
  unaff_s8 = flen;
  if (param_1 == 0x72) {
    if (param_4 != (undefined4 *)0x0) {
      iVar2 = RSA_public_decrypt((int)flen,(uchar *)param_6,(uchar *)param_4,param_8,1);
      if (iVar2 < 1) {
        uVar10 = 0;
        goto LAB_0050ea60;
      }
      *param_5 = iVar2;
      uVar10 = 1;
      goto LAB_0050ea60;
    }
    param_7 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(flen,"rsa_sign.c",199);
    if (param_7 == (uchar *)0x0) goto LAB_0050ea9c;
    if (param_3 == 0x24) {
      iVar2 = RSA_public_decrypt((int)flen,(uchar *)param_6,param_7,param_8,1);
      if (iVar2 < 1) goto LAB_0050eb20;
      if ((iVar2 == 0x24) &&
         (iVar2 = (*(code *)PTR_memcmp_006a9ad0)(param_7,param_2,0x24), iVar2 == 0))
      goto LAB_0050ec0c;
      uVar7 = 0x68;
      uVar10 = 0xe5;
    }
    else {
      uVar7 = 0x83;
      uVar10 = 0xcd;
    }
LAB_0050eb10:
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,uVar7,"rsa_sign.c",uVar10);
LAB_0050eb20:
    unaff_s7 = 0x660000;
    uVar10 = 0;
    goto LAB_0050e9cc;
  }
  param_7 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(flen,"rsa_sign.c",199);
  if (param_7 == (uchar *)0x0) {
LAB_0050ea9c:
    unaff_s7 = 0x660000;
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,0x41,"rsa_sign.c",0xc9);
    uVar10 = 0;
    goto LAB_0050ea60;
  }
  iVar2 = RSA_public_decrypt((int)flen,(uchar *)param_6,param_7,param_8,1);
  if (iVar2 < 1) goto LAB_0050eb20;
  if ((((param_1 == 0x5f) && (iVar2 == 0x12)) && (*param_7 == '\x04')) && (param_7[1] == '\x10')) {
    if (param_4 != (undefined4 *)0x0) {
      uVar10 = 1;
      uVar8 = *(undefined4 *)(param_7 + 6);
      uVar6 = *(undefined4 *)(param_7 + 10);
      uVar7 = *(undefined4 *)(param_7 + 0xe);
      *param_4 = *(undefined4 *)(param_7 + 2);
      param_4[1] = uVar8;
      param_4[2] = uVar6;
      param_4[3] = uVar7;
      *param_5 = 0x10;
      goto LAB_0050e9cc;
    }
    iVar2 = (*(code *)PTR_memcmp_006a9ad0)(param_2,param_7 + 2,0x10);
    if (iVar2 == 0) {
LAB_0050ec0c:
      unaff_s7 = 0x660000;
      uVar10 = 1;
      goto LAB_0050e9cc;
    }
    uVar7 = 0x68;
    uVar10 = 0xde;
    goto LAB_0050eb10;
  }
  local_34 = param_7;
  param_6 = (int *)(*(code *)PTR_d2i_X509_SIG_006a8738)(0,&local_34,iVar2);
  if (param_6 == (int *)0x0) goto LAB_0050eb20;
  if (local_34 == param_7 + iVar2) {
    local_30 = 0;
    iVar3 = (*(code *)PTR_i2d_X509_SIG_006a8734)(param_6,&local_30);
    uVar10 = local_30;
    if (0 < iVar3) {
      if (iVar3 == iVar2) {
        iVar3 = (*(code *)PTR_memcmp_006a9ad0)(param_7,local_30,iVar2);
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(uVar10,iVar2);
        (*(code *)PTR_CRYPTO_free_006a6e88)(local_30);
        if (iVar3 == 0) {
          puVar4 = (undefined4 *)*param_6;
          if (puVar4[1] != 0) {
            iVar2 = (*(code *)PTR_ASN1_TYPE_get_006a74b0)();
            if (iVar2 != 5) {
              (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,0x68,"rsa_sign.c",0xfb);
              goto LAB_0050e9b8;
            }
            puVar4 = (undefined4 *)*param_6;
          }
          iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar4);
          if (param_1 == iVar2) goto LAB_0050ed84;
          if (param_1 == 4) {
            if (iVar2 == 8) goto LAB_0050ed60;
          }
          else if ((param_1 == 3) && (iVar2 == 7)) {
LAB_0050ed60:
            (*(code *)PTR_fwrite_006a9a74)
                      ("signature has problems, re-make with post SSLeay045\n",1,0x34,
                       *(undefined4 *)PTR_stderr_006a9af8);
LAB_0050ed84:
            if (param_4 == (undefined4 *)0x0) {
              if (param_3 != *(int *)param_6[1]) goto LAB_0050ee9c;
              iVar2 = (*(code *)PTR_memcmp_006a9ad0)(param_2,((int *)param_6[1])[2],param_3);
              if (iVar2 != 0) goto LAB_0050ee9c;
              uVar10 = 1;
              goto LAB_0050e9bc;
            }
            uVar10 = (*(code *)PTR_OBJ_nid2sn_006a709c)(param_1);
            iVar2 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar10);
            if (iVar2 == 0) {
              piVar5 = (int *)param_6[1];
            }
            else {
              iVar2 = (*(code *)PTR_EVP_MD_size_006a7e3c)(iVar2);
              piVar5 = (int *)param_6[1];
              if (iVar2 != *piVar5) {
                pcVar9 = "rsa_sign.c";
                uVar7 = 0x8f;
                uVar10 = 0x119;
                goto LAB_0050eddc;
              }
            }
            uVar10 = 1;
            (*(code *)PTR_memcpy_006a9aec)(param_4,piVar5[2],*piVar5);
            *param_5 = *(int *)param_6[1];
            goto LAB_0050e9bc;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,100,"rsa_sign.c",0x111);
          goto LAB_0050e9b8;
        }
      }
      else {
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_30,iVar3);
        (*(code *)PTR_CRYPTO_free_006a6e88)(local_30);
      }
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,0x68,"rsa_sign.c",0xf1);
LAB_0050e9b8:
  while( true ) {
    uVar10 = 0;
LAB_0050e9bc:
    (*(code *)PTR_X509_SIG_free_006a7ca8)(param_6);
LAB_0050e9cc:
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(param_7,flen);
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_7);
    unaff_s8 = flen;
LAB_0050ea60:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    flen = unaff_s8;
LAB_0050ee9c:
    pcVar9 = (char *)(unaff_s7 + 0x6d00);
    uVar7 = 0x68;
    uVar10 = 0x121;
LAB_0050eddc:
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,uVar7,pcVar9,uVar10);
  }
  return uVar10;
}

