
/* WARNING: Could not reconcile some variable overlaps */

int AES_wrap_key(AES_KEY *key,uchar *iv,uchar *out,uchar *in,uint inlen)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  int local_2c;
  
  local_2c = __TMC_END__;
  if (((inlen & 7) == 0) && (7 < inlen)) {
    iVar4 = 6;
    memcpy(out + 8,in,inlen);
    if (iv == (uchar *)0x0) {
      iv = &default_iv;
    }
    uVar3 = 1;
    local_40 = *(undefined4 *)iv;
    local_3c = *(uint *)((int)iv + 4);
    do {
      uVar5 = 0;
      puVar2 = (undefined4 *)(out + 8);
      do {
        local_38 = *puVar2;
        uStack_34 = puVar2[1];
        AES_encrypt((uchar *)&local_40,(uchar *)&local_40,key);
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
        uVar5 = uVar5 + 8;
        uVar3 = uVar3 + 1;
        *puVar2 = local_38;
        puVar2[1] = uStack_34;
        puVar2 = puVar2 + 2;
      } while (uVar5 < inlen);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = inlen + 8;
    *(undefined4 *)out = local_40;
    *(uint *)(out + 4) = local_3c;
  }
  else {
    iVar4 = -1;
  }
  if (local_2c == __TMC_END__) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

