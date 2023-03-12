
/* WARNING: Could not reconcile some variable overlaps */

int AES_unwrap_key(AES_KEY *key,uchar *iv,uchar *out,uchar *in,uint inlen)

{
  uint uVar1;
  int iVar2;
  uchar *__s2;
  uint uVar3;
  uint __n;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  int local_2c;
  
  __n = inlen - 8;
  local_2c = __TMC_END__;
  if (((__n & 7) == 0) && (7 < __n)) {
    local_40 = *(undefined4 *)in;
    local_3c = *(uint *)(in + 4);
    memcpy(out,in + 8,__n);
    uVar3 = (__n >> 3) * 6;
    uVar4 = 6;
    do {
      uVar6 = 0;
      do {
        puVar5 = (undefined4 *)(out + ((inlen - 0x10) - uVar6));
        local_3c._3_1_ = local_3c._3_1_ ^ (byte)uVar3;
        uVar1 = local_3c & 0xffffff;
        local_3c = uVar1 | (uint)local_3c._3_1_ << 0x18;
        if (0xff < uVar3) {
          local_3c._2_1_ = (byte)(uVar1 >> 0x10);
          local_3c._1_1_ = (byte)(uVar1 >> 8);
          local_3c._0_1_ = (byte)uVar1;
          local_3c = CONCAT31(CONCAT21(CONCAT11(local_3c._3_1_,local_3c._2_1_ ^ (byte)(uVar3 >> 8)),
                                       local_3c._1_1_ ^ (byte)(uVar3 >> 0x10)),
                              (byte)local_3c ^ (byte)(uVar3 >> 0x18));
        }
        local_38 = *puVar5;
        uStack_34 = puVar5[1];
        uVar6 = uVar6 + 8;
        uVar3 = uVar3 - 1;
        AES_decrypt((uchar *)&local_40,(uchar *)&local_40,key);
        *puVar5 = local_38;
        puVar5[1] = uStack_34;
      } while (uVar6 < __n);
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
    __s2 = &default_iv;
    if (iv != (uchar *)0x0) {
      __s2 = iv;
    }
    iVar2 = memcmp(&local_40,__s2,8);
    if (iVar2 != 0) {
      OPENSSL_cleanse(out,__n);
      __n = uVar4;
    }
  }
  else {
    __n = 0xffffffff;
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __n;
}

