
int RSA_X931_hash_id(int nid)

{
  int iVar1;
  
  if (nid == 0x2a0) {
    return 0x34;
  }
  if (nid < 0x2a1) {
    iVar1 = 0x33;
    if (nid != 0x40) {
      return -1;
    }
  }
  else {
    iVar1 = 0x36;
    if ((nid != 0x2a1) && (iVar1 = 0x35, nid != 0x2a2)) {
      return -1;
    }
  }
  return iVar1;
}

