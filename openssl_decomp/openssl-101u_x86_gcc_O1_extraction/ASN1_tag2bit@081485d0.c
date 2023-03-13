
ulong ASN1_tag2bit(int tag)

{
  ulong uVar1;
  
  uVar1 = 0;
  if ((uint)tag < 0x1f) {
    uVar1 = *(ulong *)(tag2bit + tag * 4);
  }
  return uVar1;
}

