
int RSA_padding_add_PKCS1_PSS_mgf1
              (RSA *rsa,uchar *EM,uchar *mHash,EVP_MD *Hash,EVP_MD *mgf1Hash,int sLen)

{
  uint *puVar1;
  size_t cnt;
  int iVar2;
  byte *buf;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar7;
  byte *pbVar8;
  uint cnt_00;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  EVP_MD_CTX EStack_40;
  byte *pbVar6;
  
  if (mgf1Hash == (EVP_MD *)0x0) {
    mgf1Hash = Hash;
  }
  cnt = EVP_MD_size(Hash);
  if ((int)cnt < 0) {
    return 0;
  }
  cnt_00 = cnt;
  if (sLen != -1) {
    cnt_00 = sLen;
    if ((sLen != -2) && (sLen + 2 < 0 != SCARRY4(sLen,2))) {
      ERR_put_error(4,0x94,0x88,"rsa_pss.c",0xdc);
      return 0;
    }
  }
  iVar2 = BN_num_bits(rsa->n);
  uVar10 = iVar2 - 1U & 7;
  iVar2 = RSA_size(rsa);
  if (uVar10 == 0) {
    *EM = '\0';
    iVar2 = iVar2 + -1;
    EM = EM + 1;
  }
  if (cnt_00 == 0xfffffffe) {
    cnt_00 = (iVar2 - cnt) - 2;
  }
  else if (iVar2 <= (int)(cnt + cnt_00 + 1)) {
    ERR_put_error(4,0x94,0x6e,"rsa_pss.c",0xed);
    return 0;
  }
  if ((int)cnt_00 < 1) {
    buf = (byte *)0x0;
  }
  else {
    buf = (byte *)CRYPTO_malloc(cnt_00,"rsa_pss.c",0xf2);
    if (buf == (byte *)0x0) {
      ERR_put_error(4,0x94,0x41,"rsa_pss.c",0xf5);
      return 0;
    }
    iVar3 = RAND_bytes(buf,cnt_00);
    if (iVar3 < 1) {
      iVar3 = 0;
      goto LAB_001216bc;
    }
  }
  EVP_MD_CTX_init(&EStack_40);
  iVar3 = EVP_DigestInit_ex(&EStack_40,Hash,(ENGINE *)0x0);
  if ((((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&EStack_40,&zeroes,8), iVar3 == 0)) ||
      (iVar3 = EVP_DigestUpdate(&EStack_40,mHash,cnt), iVar3 == 0)) ||
     ((cnt_00 != 0 && (iVar3 = EVP_DigestUpdate(&EStack_40,buf,cnt_00), iVar3 == 0)))) {
LAB_001216b4:
    iVar3 = 0;
  }
  else {
    iVar7 = (iVar2 - cnt) + -1;
    iVar3 = EVP_DigestFinal_ex(&EStack_40,EM + iVar7,(uint *)0x0);
    if (iVar3 == 0) goto LAB_001216b4;
    EVP_MD_CTX_cleanup(&EStack_40);
    uVar4 = PKCS1_MGF1(EM,iVar7,EM + iVar7,cnt,mgf1Hash);
    if (uVar4 != 0) goto LAB_001216b4;
    iVar3 = (iVar2 - cnt_00) - cnt;
    pbVar8 = EM + iVar3 + -1;
    EM[iVar3 + -2] = EM[iVar3 + -2] ^ 1;
    if (0 < (int)cnt_00) {
      if ((((uint)buf | (uint)(EM + iVar3 + -1)) & 3) == 0 &&
          (6 < cnt_00 && (EM + iVar3 + 3 <= buf || buf + 4 <= EM + iVar3 + -1))) {
        uVar9 = cnt_00 & 0xfffffffc;
        uVar11 = uVar4;
        do {
          iVar7 = uVar4 + iVar3;
          uVar11 = uVar11 + 1;
          puVar1 = (uint *)(buf + uVar4);
          uVar4 = uVar4 + 4;
          *(uint *)(EM + iVar7 + -1) = *puVar1 ^ *(uint *)(EM + iVar7 + -1);
        } while (uVar11 < cnt_00 >> 2);
        if (cnt_00 != uVar9) {
          pbVar8[cnt_00 & 0xfffffffc] = buf[cnt_00 & 0xfffffffc] ^ pbVar8[cnt_00 & 0xfffffffc];
          if ((int)(uVar9 + 1) < (int)cnt_00) {
            pbVar8[uVar9 + 1] = pbVar8[uVar9 + 1] ^ buf[uVar9 + 1];
            if ((int)(uVar9 + 2) < (int)cnt_00) {
              pbVar8[uVar9 + 2] = pbVar8[uVar9 + 2] ^ buf[uVar9 + 2];
            }
          }
        }
      }
      else {
        pbVar6 = buf;
        do {
          pbVar5 = pbVar6 + 1;
          *pbVar8 = *pbVar8 ^ *pbVar6;
          pbVar6 = pbVar5;
          pbVar8 = pbVar8 + 1;
        } while (pbVar5 != buf + cnt_00);
      }
    }
    if (uVar10 != 0) {
      *EM = (byte)(0xff >> (8 - uVar10 & 0xff)) & *EM;
    }
    iVar3 = 1;
    EM[iVar2 + -1] = 0xbc;
  }
  if (buf == (byte *)0x0) {
    return iVar3;
  }
LAB_001216bc:
  CRYPTO_free(buf);
  return iVar3;
}

