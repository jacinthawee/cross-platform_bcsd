
int PEM_ASN1_write_bio(undefined1 *i2d,char *name,BIO *bp,void *x,EVP_CIPHER *enc,uchar *kstr,
                      int klen,undefined1 *cb,void *u)

{
  uchar uVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  EVP_CIPHER *enc_00;
  EVP_CIPHER *data;
  BIO *bp_00;
  EVP_CIPHER *pEVar7;
  undefined1 *i2d_00;
  char *name_00;
  uchar *puVar8;
  char *pcVar9;
  char *x_00;
  int iVar10;
  uint uVar11;
  EVP_CIPHER *in_stack_fffffac0;
  uchar *local_53c;
  EVP_CIPHER *local_538;
  undefined1 *local_534;
  undefined local_514 [8];
  EVP_CIPHER *local_50c;
  undefined auStack_508 [140];
  undefined local_47c [16];
  EVP_CIPHER EStack_46c;
  undefined local_42c [1024];
  undefined1 *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(undefined1 **)PTR___stack_chk_guard_006a9ae8;
  if (enc == (EVP_CIPHER *)0x0) {
    iVar5 = 0;
LAB_0056c144:
    name_00 = (char *)(*(code *)i2d)(x,0);
    if ((int)name_00 < 0) {
      pcVar9 = &DAT_0000000d;
      enc_00 = (EVP_CIPHER *)0x162;
      goto LAB_0056c098;
    }
    data = (EVP_CIPHER *)(*(code *)PTR_CRYPTO_malloc_006a7008)(name_00 + 0x14,"pem_lib.c",0x168);
    if (data != (EVP_CIPHER *)0x0) {
      local_50c = data;
      enc_00 = (EVP_CIPHER *)(*(code *)i2d)(x,&local_50c);
      if (enc == (EVP_CIPHER *)0x0) {
        local_42c[0] = 0;
LAB_0056c5a4:
        pcVar9 = (char *)(EVP_CIPHER *)local_42c;
        x_00 = (char *)data;
        local_514._0_4_ = enc_00;
        local_514._0_4_ =
             (EVP_CIPHER *)
             PEM_write_bio(bp,name,(char *)(EVP_CIPHER *)local_42c,(uchar *)data,(long)enc_00);
        uVar11 = (uint)(0 < (int)local_514._0_4_);
      }
      else {
        local_514._0_4_ = enc_00;
        if (kstr == (uchar *)0x0) {
          if (cb == (undefined1 *)0x0) {
            klen = PEM_def_callback((char *)(EVP_CIPHER *)local_42c,0x400,1,u);
          }
          else {
            klen = (*(code *)cb)();
          }
          kstr = (uchar *)(EVP_CIPHER *)local_42c;
          if (0 < klen) goto LAB_0056c1b4;
          pcVar9 = &DAT_0000006f;
          x_00 = "pem_lib.c";
          uVar11 = 0;
          enc_00 = (EVP_CIPHER *)0x177;
          (*(code *)PTR_ERR_put_error_006a7f34)(9,0x69,0x6f);
        }
        else {
LAB_0056c1b4:
          x_00 = (char *)0x0;
          pcVar9 = (char *)0x0;
          (*(code *)PTR_RAND_add_006a8004)(data,local_514._0_4_,0);
          iVar6 = enc->iv_len;
          if (0x10 < iVar6) {
            pcVar9 = "enc->iv_len <= (int)sizeof(iv)";
            (*(code *)PTR_OpenSSLDie_006a7c5c)("pem_lib.c",0x181,"enc->iv_len <= (int)sizeof(iv)");
            iVar6 = enc->iv_len;
          }
          enc_00 = (EVP_CIPHER *)local_47c;
          iVar6 = (*(code *)PTR_RAND_bytes_006a7574)(enc_00,iVar6);
          if (0 < iVar6) {
            local_538 = (EVP_CIPHER *)(local_47c + 0x10);
            uVar4 = (*(code *)PTR_EVP_md5_006a70c8)();
            local_534 = (undefined1 *)0x0;
            local_53c = (uchar *)0x1;
            pcVar9 = (char *)enc_00;
            x_00 = (char *)kstr;
            iVar6 = (*(code *)PTR_EVP_BytesToKey_006a754c)(enc,uVar4,enc_00);
            in_stack_fffffac0 = (EVP_CIPHER *)klen;
            if (iVar6 != 0) {
              if ((EVP_CIPHER *)kstr == (EVP_CIPHER *)local_42c) {
                (*(code *)PTR_OPENSSL_cleanse_006a7074)((EVP_CIPHER *)local_42c,0x400);
              }
              iVar6 = (*(code *)PTR_strlen_006a9a24)(iVar5);
              if (0x400 < (uint)(enc->iv_len * 2 + 0x24 + iVar6)) {
                (*(code *)PTR_OpenSSLDie_006a7c5c)
                          ("pem_lib.c",399,
                           "strlen(objstr) + 23 + 2 * enc->iv_len + 13 <= sizeof buf");
              }
              local_42c[0] = 0;
              (*(code *)PTR_BUF_strlcat_006a6f68)((EVP_CIPHER *)local_42c,"Proc-Type: 4,",0x400);
              (*(code *)PTR_BUF_strlcat_006a6f68)((EVP_CIPHER *)local_42c,"ENCRYPTED",0x400);
              (*(code *)PTR_BUF_strlcat_006a6f68)((EVP_CIPHER *)local_42c,"\n",0x400);
              iVar6 = enc->iv_len;
              (*(code *)PTR_BUF_strlcat_006a6f68)((EVP_CIPHER *)local_42c,"DEK-Info: ",0x400);
              (*(code *)PTR_BUF_strlcat_006a6f68)((EVP_CIPHER *)local_42c,iVar5,0x400);
              (*(code *)PTR_BUF_strlcat_006a6f68)((EVP_CIPHER *)local_42c,",",0x400);
              iVar5 = (*(code *)PTR_strlen_006a9a24)((EVP_CIPHER *)local_42c);
              iVar10 = iVar6 * 2;
              if (iVar5 + iVar10 < 0x400) {
                if (iVar6 < 1) {
                  iVar10 = 0;
                }
                else {
                  pEVar7 = enc_00;
                  puVar8 = (uchar *)((int)&((EVP_CIPHER *)local_42c)->nid + iVar5);
                  do {
                    piVar2 = &pEVar7->nid;
                    pEVar7 = (EVP_CIPHER *)((int)&pEVar7->nid + 1);
                    uVar1 = "0123456789ABCDEF"[(int)(char)*(uchar *)piVar2 & 0xf];
                    *puVar8 = "0123456789ABCDEF"
                              [(uint)((int)(char)*(uchar *)piVar2 << 0x18) >> 0x1c];
                    puVar8[1] = uVar1;
                    puVar8 = puVar8 + 2;
                  } while (pEVar7 != (EVP_CIPHER *)((int)&enc_00->nid + iVar6));
                }
                local_42c[iVar5 + iVar10 + 1] = 0;
                local_42c[iVar5 + iVar10] = 10;
              }
              (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_508);
              pcVar9 = (char *)0x0;
              x_00 = (char *)local_538;
              iVar5 = (*(code *)PTR_EVP_EncryptInit_ex_006a7a98)(auStack_508,enc,0);
              if (iVar5 != 0) {
                pcVar9 = local_514 + 4;
                x_00 = (char *)data;
                enc_00 = local_514._0_4_;
                iVar5 = (*(code *)PTR_EVP_EncryptUpdate_006a7aa0)(auStack_508,data,pcVar9);
                if (iVar5 != 0) {
                  pcVar9 = local_514;
                  iVar5 = (*(code *)PTR_EVP_EncryptFinal_ex_006a7a9c)
                                    (auStack_508,(uchar *)((int)&data->nid + local_514._4_4_),pcVar9
                                    );
                  if (iVar5 != 0) {
                    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_508);
                    enc_00 = (EVP_CIPHER *)((int)&(local_514._0_4_)->nid + local_514._4_4_);
                    goto LAB_0056c5a4;
                  }
                }
              }
              uVar11 = 0;
              (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_508);
              goto LAB_0056c41c;
            }
          }
          enc_00 = in_stack_fffffac0;
          uVar11 = 0;
        }
      }
LAB_0056c41c:
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_47c + 0x10,0x40);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_47c,0x10);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_508,0x8c);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)((EVP_CIPHER *)local_42c,0x400);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(data);
      (*(code *)PTR_CRYPTO_free_006a6e88)(data);
      goto LAB_0056c100;
    }
    pcVar9 = &DAT_00000041;
    x_00 = "pem_lib.c";
    enc_00 = (EVP_CIPHER *)0x16a;
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x69,0x41);
  }
  else {
    uVar4 = (*(code *)PTR_EVP_CIPHER_nid_006a73d0)(enc);
    iVar5 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar4);
    if ((iVar5 != 0) && (iVar6 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(enc), iVar6 != 0))
    goto LAB_0056c144;
    pcVar9 = (char *)0x71;
    enc_00 = (EVP_CIPHER *)0x15c;
LAB_0056c098:
    x_00 = "pem_lib.c";
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x69,pcVar9);
  }
  uVar11 = 0;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_47c + 0x10,0x40);
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_47c,0x10);
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_508,0x8c);
  name_00 = &DAT_00000400;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_42c);
LAB_0056c100:
  if (local_2c == *(undefined1 **)puVar3) {
    return uVar11;
  }
  i2d_00 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  bp_00 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  if (bp_00 == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x68,7,"pem_lib.c",0x143);
    return 0;
  }
  (*(code *)PTR_BIO_ctrl_006a6e18)(bp_00,0x6a,0,pcVar9);
  iVar5 = PEM_ASN1_write_bio(i2d_00,name_00,bp_00,x_00,enc_00,local_53c,(int)local_538,local_534,
                             &_gp);
  (*(code *)PTR_BIO_free_006a6e70)(bp_00);
  return iVar5;
}

