
int PKCS12_key_gen_uni(uchar *pass,int passlen,uchar *salt,int saltlen,int id,int iter,int n,
                      uchar *out,EVP_MD *md_type)

{
  size_t __n;
  size_t cnt;
  int iVar1;
  void *__s;
  uchar *md;
  uchar *s;
  size_t cnt_00;
  uchar *d;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *pBVar2;
  int iVar3;
  size_t sVar4;
  uchar *puVar5;
  int in_GS_OFFSET;
  uchar *to;
  int local_60;
  uchar *local_4c;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_4c = out;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_38);
  __n = EVP_MD_block_size(md_type);
  cnt = EVP_MD_size(md_type);
  iVar1 = 0;
  if (-1 < (int)cnt) {
    __s = CRYPTO_malloc(__n,"p12_key.c",0x8d);
    md = (uchar *)CRYPTO_malloc(cnt,"p12_key.c",0x8e);
    s = (uchar *)CRYPTO_malloc(__n + 1,"p12_key.c",0x8f);
    iVar1 = ((int)((__n - 1) + saltlen) / (int)__n) * __n;
    local_60 = 0;
    if (passlen != 0) {
      local_60 = ((int)((__n - 1) + passlen) / (int)__n) * __n;
    }
    cnt_00 = local_60 + iVar1;
    d = (uchar *)CRYPTO_malloc(cnt_00,"p12_key.c",0x96);
    ret = BN_new();
    ret_00 = BN_new();
    if (((((__s != (void *)0x0) && (md != (uchar *)0x0)) && (s != (uchar *)0x0)) &&
        ((d != (uchar *)0x0 && (ret != (BIGNUM *)0x0)))) && (ret_00 != (BIGNUM *)0x0)) {
      if (0 < (int)__n) {
        memset(__s,id & 0xff,__n);
      }
      iVar3 = 0;
      puVar5 = d;
      if (0 < iVar1) {
        do {
          d[iVar3] = salt[iVar3 % saltlen];
          iVar3 = iVar3 + 1;
        } while (iVar1 != iVar3);
        puVar5 = d + iVar1;
      }
      iVar1 = 0;
      if (0 < local_60) {
        do {
          puVar5[iVar1] = pass[iVar1 % passlen];
          iVar1 = iVar1 + 1;
        } while (local_60 != iVar1);
      }
      while (((iVar1 = EVP_DigestInit_ex(&local_38,md_type,(ENGINE *)0x0), iVar1 != 0 &&
              (iVar1 = EVP_DigestUpdate(&local_38,__s,__n), iVar1 != 0)) &&
             ((iVar1 = EVP_DigestUpdate(&local_38,d,cnt_00), iVar1 != 0 &&
              (iVar1 = EVP_DigestFinal_ex(&local_38,md,(uint *)0x0), iVar1 != 0))))) {
        iVar1 = 1;
        if (1 < iter) {
          do {
            iVar3 = EVP_DigestInit_ex(&local_38,md_type,(ENGINE *)0x0);
            if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&local_38,md,cnt), iVar3 == 0)) ||
               (iVar3 = EVP_DigestFinal_ex(&local_38,md,(uint *)0x0), iVar3 == 0))
            goto LAB_08181f98;
            iVar1 = iVar1 + 1;
          } while (iter != iVar1);
        }
        sVar4 = cnt;
        if (n <= (int)cnt) {
          sVar4 = n;
        }
        memcpy(local_4c,md,sVar4);
        if (n <= (int)cnt) {
          iVar1 = 1;
          goto LAB_08181fb5;
        }
        sVar4 = 0;
        if (0 < (int)__n) {
          do {
            s[sVar4] = md[(int)sVar4 % (int)cnt];
            sVar4 = sVar4 + 1;
          } while (__n != sVar4);
        }
        pBVar2 = BN_bin2bn(s,__n,ret_00);
        if ((pBVar2 == (BIGNUM *)0x0) || (iVar1 = BN_add_word(ret_00,1), iVar1 == 0)) break;
        puVar5 = d;
        if (0 < (int)cnt_00) {
          do {
            pBVar2 = BN_bin2bn(puVar5,__n,ret);
            if (((pBVar2 == (BIGNUM *)0x0) || (iVar1 = BN_add(ret,ret,ret_00), iVar1 == 0)) ||
               (iVar1 = BN_bn2bin(ret,s), iVar1 == 0)) goto LAB_08181f98;
            iVar3 = BN_num_bits(ret);
            iVar1 = iVar3 + 0xe;
            if (-1 < iVar3 + 7) {
              iVar1 = iVar3 + 7;
            }
            iVar1 = iVar1 >> 3;
            if ((int)__n < iVar1) {
              iVar1 = BN_bn2bin(ret,s);
              if (iVar1 == 0) goto LAB_08181f98;
              memcpy(puVar5,s + 1,__n);
            }
            else {
              to = puVar5;
              if (iVar1 < (int)__n) {
                memset(puVar5,0,__n - iVar1);
                to = d + (int)(puVar5 + ((__n - (int)d) - iVar1));
              }
              iVar1 = BN_bn2bin(ret,to);
              if (iVar1 == 0) goto LAB_08181f98;
            }
            puVar5 = puVar5 + __n;
          } while ((int)puVar5 - (int)d < (int)cnt_00);
        }
        n = n - cnt;
        local_4c = local_4c + cnt;
      }
    }
LAB_08181f98:
    iVar1 = 0;
    ERR_put_error(0x23,0x6f,0x41,"p12_key.c",0xda);
LAB_08181fb5:
    CRYPTO_free(md);
    CRYPTO_free(s);
    CRYPTO_free(__s);
    CRYPTO_free(d);
    BN_free(ret);
    BN_free(ret_00);
    EVP_MD_CTX_cleanup(&local_38);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

