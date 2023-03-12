
int PEM_ASN1_write_bio(undefined1 *i2d,char *name,BIO *bp,void *x,EVP_CIPHER *enc,uchar *kstr,
                      int klen,undefined1 *cb,void *u)

{
  uchar uVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  char *name_00;
  uchar *data;
  EVP_CIPHER *enc_00;
  BIO *bp_00;
  EVP_CIPHER *pEVar6;
  undefined1 *i2d_00;
  int iVar7;
  uchar *puVar8;
  char *hdr;
  int iVar9;
  uint uVar10;
  EVP_CIPHER *in_stack_fffffac0;
  uchar *local_53c;
  undefined *local_538;
  undefined1 *local_534;
  char *local_528;
  undefined local_514 [8];
  uchar *local_50c;
  undefined auStack_508 [140];
  undefined local_47c [80];
  undefined local_42c [1024];
  undefined1 *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(undefined1 **)PTR___stack_chk_guard_006aabf0;
  if (enc == (EVP_CIPHER *)0x0) {
    iVar5 = 0;
LAB_0056f950:
    name_00 = (char *)(*(code *)i2d)(x,0);
    if ((int)name_00 < 0) {
      hdr = &DAT_0000000d;
      enc_00 = (EVP_CIPHER *)0x165;
      goto LAB_0056fcd8;
    }
    data = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(name_00 + 0x14,"pem_lib.c",0x16b);
    if (data != (uchar *)0x0) {
      local_50c = data;
      enc_00 = (EVP_CIPHER *)(*(code *)i2d)(x,&local_50c);
      if (enc == (EVP_CIPHER *)0x0) {
        local_42c[0] = '\0';
LAB_0056fd5c:
        hdr = local_42c;
        local_528 = (char *)data;
        local_514._0_4_ = enc_00;
        local_514._0_4_ = (EVP_CIPHER *)PEM_write_bio(bp,name,hdr,data,(long)enc_00);
        uVar10 = (uint)(0 < (int)local_514._0_4_);
      }
      else {
        local_514._0_4_ = enc_00;
        if (kstr == (uchar *)0x0) {
          if (cb == (undefined1 *)0x0) {
            klen = PEM_def_callback(local_42c,0x400,1,u);
          }
          else {
            klen = (*(code *)cb)(local_42c,0x400,1);
          }
          kstr = local_42c;
          if (0 < klen) goto LAB_0056f9b8;
          local_528 = "pem_lib.c";
          hdr = &DAT_0000006f;
          enc_00 = (EVP_CIPHER *)0x17e;
          (*(code *)PTR_ERR_put_error_006a9030)(9,0x69,0x6f);
          uVar10 = 0;
        }
        else {
LAB_0056f9b8:
          local_528 = (char *)0x0;
          hdr = (char *)0x0;
          (*(code *)PTR_RAND_add_006a9020)(data,local_514._0_4_,0);
          iVar7 = enc->iv_len;
          if (0x10 < iVar7) {
            hdr = "enc->iv_len <= (int)sizeof(iv)";
            (*(code *)PTR_OpenSSLDie_006a8d4c)("pem_lib.c",0x188,"enc->iv_len <= (int)sizeof(iv)");
            iVar7 = enc->iv_len;
          }
          enc_00 = (EVP_CIPHER *)local_47c;
          iVar7 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(enc_00,iVar7);
          if (-1 < iVar7) {
            local_538 = local_47c + 0x10;
            uVar4 = (*(code *)PTR_EVP_md5_006a81c8)();
            local_534 = (undefined1 *)0x0;
            local_53c = (uchar *)0x1;
            hdr = (char *)enc_00;
            local_528 = (char *)kstr;
            iVar7 = (*(code *)PTR_EVP_BytesToKey_006a8644)(enc,uVar4,enc_00);
            in_stack_fffffac0 = (EVP_CIPHER *)klen;
            if (iVar7 != 0) {
              if (kstr == local_42c) {
                (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_42c,0x400);
              }
              local_528 = local_47c + 0x10;
              iVar7 = (*(code *)PTR_strlen_006aab30)(iVar5);
              if (0x400 < (uint)(enc->iv_len * 2 + 0x24 + iVar7)) {
                (*(code *)PTR_OpenSSLDie_006a8d4c)
                          ("pem_lib.c",0x192,"strlen(objstr)+23+2*enc->iv_len+13 <= sizeof buf");
              }
              local_42c[0] = '\0';
              (*(code *)PTR_BUF_strlcat_006a8068)(local_42c,"Proc-Type: 4,",0x400);
              (*(code *)PTR_BUF_strlcat_006a8068)(local_42c,"ENCRYPTED",0x400);
              (*(code *)PTR_BUF_strlcat_006a8068)(local_42c,"\n",0x400);
              iVar7 = enc->iv_len;
              (*(code *)PTR_BUF_strlcat_006a8068)(local_42c,"DEK-Info: ",0x400);
              (*(code *)PTR_BUF_strlcat_006a8068)(local_42c,iVar5,0x400);
              (*(code *)PTR_BUF_strlcat_006a8068)(local_42c,",",0x400);
              iVar5 = (*(code *)PTR_strlen_006aab30)(local_42c);
              iVar9 = iVar7 * 2;
              if (iVar5 + iVar9 < 0x400) {
                if (iVar7 < 1) {
                  iVar9 = 0;
                }
                else {
                  pEVar6 = enc_00;
                  puVar8 = local_42c + iVar5;
                  do {
                    piVar2 = &pEVar6->nid;
                    pEVar6 = (EVP_CIPHER *)((int)&pEVar6->nid + 1);
                    uVar1 = "0123456789ABCDEF"[(int)*(char *)piVar2 & 0xf];
                    *puVar8 = "0123456789ABCDEF"[(uint)((int)*(char *)piVar2 << 0x18) >> 0x1c];
                    puVar8[1] = uVar1;
                    puVar8 = puVar8 + 2;
                  } while (pEVar6 != (EVP_CIPHER *)((int)&enc_00->nid + iVar7));
                }
                local_42c[iVar5 + iVar9 + 1] = 0;
                local_42c[iVar5 + iVar9] = 10;
              }
              (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_508);
              hdr = (char *)0x0;
              iVar5 = (*(code *)PTR_EVP_EncryptInit_ex_006a8b84)(auStack_508,enc,0);
              if (iVar5 != 0) {
                hdr = local_514 + 4;
                local_528 = (char *)data;
                enc_00 = local_514._0_4_;
                iVar5 = (*(code *)PTR_EVP_EncryptUpdate_006a8b8c)(auStack_508,data,hdr);
                if (iVar5 != 0) {
                  hdr = local_514;
                  iVar5 = (*(code *)PTR_EVP_EncryptFinal_ex_006a8b88)
                                    (auStack_508,data + local_514._4_4_,hdr);
                  if (iVar5 != 0) {
                    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_508);
                    enc_00 = (EVP_CIPHER *)((int)&(local_514._0_4_)->nid + local_514._4_4_);
                    goto LAB_0056fd5c;
                  }
                }
              }
              uVar10 = 0;
              (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_508);
              goto LAB_0056fc14;
            }
          }
          enc_00 = in_stack_fffffac0;
          uVar10 = 0;
        }
      }
LAB_0056fc14:
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_47c + 0x10,0x40);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_47c,0x10);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_508,0x8c);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_42c,0x400);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(data);
      (*(code *)PTR_CRYPTO_free_006a7f88)(data);
      goto LAB_0056fc84;
    }
    local_528 = "pem_lib.c";
    hdr = &DAT_00000041;
    enc_00 = (EVP_CIPHER *)&DAT_0000016e;
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x69,0x41);
  }
  else {
    uVar4 = (*(code *)PTR_EVP_CIPHER_nid_006a84d0)(enc);
    iVar5 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar4);
    if (iVar5 != 0) goto LAB_0056f950;
    hdr = (char *)0x71;
    enc_00 = (EVP_CIPHER *)0x15e;
LAB_0056fcd8:
    local_528 = "pem_lib.c";
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x69,hdr);
  }
  uVar10 = 0;
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_47c + 0x10,0x40);
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_47c,0x10);
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_508,0x8c);
  name_00 = &DAT_00000400;
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_42c);
LAB_0056fc84:
  if (local_2c == *(undefined1 **)puVar3) {
    return uVar10;
  }
  i2d_00 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  bp_00 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  if (bp_00 == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x68,7,"pem_lib.c",0x143);
    return 0;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(bp_00,0x6a,0,hdr);
  iVar5 = PEM_ASN1_write_bio(i2d_00,name_00,bp_00,local_528,enc_00,local_53c,(int)local_538,
                             local_534,&_gp);
  (*(code *)PTR_BIO_free_006a7f70)(bp_00);
  return iVar5;
}

