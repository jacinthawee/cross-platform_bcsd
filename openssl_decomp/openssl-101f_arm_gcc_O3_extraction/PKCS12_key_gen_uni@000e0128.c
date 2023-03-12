
int PKCS12_key_gen_uni(uchar *pass,int passlen,uchar *salt,int saltlen,int id,int iter,int n,
                      uchar *out,EVP_MD *md_type)

{
  size_t __n;
  size_t cnt;
  int iVar1;
  void *__s;
  uchar *md;
  uchar *s;
  uchar *d;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *pBVar2;
  int iVar3;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  size_t cnt_00;
  uchar *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  size_t sVar7;
  int local_68;
  EVP_MD_CTX EStack_40;
  
  EVP_MD_CTX_init(&EStack_40);
  __n = EVP_MD_block_size(md_type);
  cnt = EVP_MD_size(md_type);
  if ((int)cnt < 0) {
    iVar1 = 0;
  }
  else {
    __s = CRYPTO_malloc(__n,"p12_key.c",0x8a);
    md = (uchar *)CRYPTO_malloc(cnt,"p12_key.c",0x8b);
    s = (uchar *)CRYPTO_malloc(__n + 1,"p12_key.c",0x8c);
    iVar1 = __aeabi_idiv(saltlen + __n + -1,__n);
    iVar1 = __n * iVar1;
    local_68 = passlen;
    if (passlen != 0) {
      local_68 = __aeabi_idiv(passlen + __n + -1,__n);
      local_68 = __n * local_68;
    }
    cnt_00 = local_68 + iVar1;
    d = (uchar *)CRYPTO_malloc(cnt_00,"p12_key.c",0x91);
    ret = BN_new();
    ret_00 = BN_new();
    if (((md != (uchar *)0x0 && __s != (void *)0x0) && (d != (uchar *)0x0 && s != (uchar *)0x0)) &&
       (ret_00 != (BIGNUM *)0x0 && ret != (BIGNUM *)0x0)) {
      if (0 < (int)__n) {
        memset(__s,id & 0xff,__n);
      }
      puVar6 = d;
      if (0 < iVar1) {
        puVar6 = d + iVar1;
        puVar5 = d;
        do {
          __aeabi_idivmod((int)puVar5 - (int)d,saltlen);
          puVar4 = puVar5 + 1;
          *puVar5 = salt[extraout_r1];
          puVar5 = puVar4;
        } while (puVar4 != puVar6);
      }
      if (0 < local_68) {
        puVar5 = puVar6;
        do {
          __aeabi_idivmod((int)puVar5 - (int)puVar6,passlen);
          puVar4 = puVar5 + 1;
          *puVar5 = pass[extraout_r1_00];
          puVar5 = puVar4;
        } while (puVar4 != puVar6 + local_68);
      }
      while (((iVar1 = EVP_DigestInit_ex(&EStack_40,md_type,(ENGINE *)0x0), iVar1 != 0 &&
              (iVar1 = EVP_DigestUpdate(&EStack_40,__s,__n), iVar1 != 0)) &&
             ((iVar1 = EVP_DigestUpdate(&EStack_40,d,cnt_00), iVar1 != 0 &&
              (iVar1 = EVP_DigestFinal_ex(&EStack_40,md,(uint *)0x0), iVar1 != 0))))) {
        if (1 < iter) {
          iVar1 = 1;
          do {
            iVar1 = iVar1 + 1;
            iVar3 = EVP_DigestInit_ex(&EStack_40,md_type,(ENGINE *)0x0);
            if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&EStack_40,md,cnt), iVar3 == 0)) ||
               (iVar3 = EVP_DigestFinal_ex(&EStack_40,md,(uint *)0x0), iVar3 == 0))
            goto LAB_000e02d6;
          } while (iVar1 != iter);
        }
        sVar7 = n;
        if ((int)cnt <= n) {
          sVar7 = cnt;
        }
        memcpy(out,md,sVar7);
        if (n <= (int)cnt) {
          iVar1 = 1;
          goto LAB_000e02ee;
        }
        if (0 < (int)__n) {
          sVar7 = 0;
          do {
            __aeabi_idivmod(sVar7,cnt);
            s[sVar7] = md[extraout_r1_01];
            sVar7 = sVar7 + 1;
          } while (sVar7 != __n);
        }
        pBVar2 = BN_bin2bn(s,__n,ret_00);
        if ((pBVar2 == (BIGNUM *)0x0) || (iVar1 = BN_add_word(ret_00,1), iVar1 == 0)) break;
        sVar7 = __n;
        if (0 < (int)cnt_00) {
          do {
            puVar6 = d + (sVar7 - __n);
            pBVar2 = BN_bin2bn(puVar6,__n,ret);
            if (((pBVar2 == (BIGNUM *)0x0) || (iVar1 = BN_add(ret,ret,ret_00), iVar1 == 0)) ||
               (iVar1 = BN_bn2bin(ret,s), iVar1 == 0)) goto LAB_000e02d6;
            iVar3 = BN_num_bits(ret);
            iVar1 = iVar3 + 0xe;
            if (-1 < iVar3 + 7) {
              iVar1 = iVar3 + 7;
            }
            iVar1 = iVar1 >> 3;
            if ((int)__n < iVar1) {
              iVar1 = BN_bn2bin(ret,s);
              if (iVar1 == 0) goto LAB_000e02d6;
              memcpy(puVar6,s + 1,__n);
            }
            else {
              if (iVar1 < (int)__n) {
                memset(puVar6,0,__n - iVar1);
                iVar1 = BN_bn2bin(ret,d + (sVar7 - iVar1));
              }
              else {
                iVar1 = BN_bn2bin(ret,puVar6);
              }
              if (iVar1 == 0) goto LAB_000e02d6;
            }
            sVar7 = sVar7 + __n;
          } while ((int)(sVar7 - __n) < (int)cnt_00);
        }
        n = n - cnt;
        out = out + cnt;
      }
    }
LAB_000e02d6:
    iVar1 = 0;
    ERR_put_error(0x23,0x6f,0x41,"p12_key.c",0xd1);
LAB_000e02ee:
    CRYPTO_free(md);
    CRYPTO_free(s);
    CRYPTO_free(__s);
    CRYPTO_free(d);
    BN_free(ret);
    BN_free(ret_00);
    EVP_MD_CTX_cleanup(&EStack_40);
  }
  return iVar1;
}

