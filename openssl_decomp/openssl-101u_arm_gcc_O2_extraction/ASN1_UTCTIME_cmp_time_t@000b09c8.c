
int ASN1_UTCTIME_cmp_time_t(ASN1_UTCTIME *s,time_t t)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  byte *pbVar5;
  int local_44 [2];
  undefined auStack_3c [44];
  
  puVar4 = s->data;
  if (puVar4[0xc] == 'Z') {
    local_44[0] = 0;
  }
  else {
    local_44[0] = (uint)puVar4[0x10] + (puVar4[0xf] - 0x30) * 10 + -0x30 +
                  ((uint)puVar4[0xe] + (puVar4[0xd] - 0x30) * 10 + -0x30) * 0x3c;
    if (puVar4[0xc] == '-') {
      local_44[0] = -local_44[0];
    }
    local_44[0] = local_44[0] * -0x3c;
  }
  local_44[0] = t + local_44[0];
  piVar1 = (int *)OPENSSL_gmtime(local_44,auStack_3c);
  if (piVar1 == (int *)0x0) {
    return -2;
  }
  pbVar5 = s->data;
  iVar2 = (uint)pbVar5[1] + (*pbVar5 - 0x30) * 10;
  iVar3 = iVar2 + -0x30;
  if (iVar3 < 0x32) {
    iVar3 = iVar2 + 0x34;
  }
  if (piVar1[5] <= iVar3) {
    if (piVar1[5] < iVar3) {
      return 1;
    }
    iVar2 = (uint)pbVar5[3] + (pbVar5[2] - 0x30) * 10;
    if (piVar1[4] < iVar2 + -0x30) {
      if (piVar1[4] < iVar2 + -0x31) {
        return 1;
      }
      iVar2 = (uint)pbVar5[5] + (pbVar5[4] - 0x30) * 10;
      if (piVar1[3] < iVar2 + -0x2f) {
        if (piVar1[3] < iVar2 + -0x30) {
          return 1;
        }
        iVar2 = (uint)pbVar5[7] + (pbVar5[6] - 0x30) * 10;
        if (piVar1[2] < iVar2 + -0x2f) {
          if (piVar1[2] < iVar2 + -0x30) {
            return 1;
          }
          iVar2 = (uint)pbVar5[9] + (pbVar5[8] - 0x30) * 10;
          if (piVar1[1] < iVar2 + -0x2f) {
            if (piVar1[1] < iVar2 + -0x30) {
              return 1;
            }
            iVar2 = (uint)pbVar5[0xb] + (pbVar5[10] - 0x30) * 10;
            if (*piVar1 < iVar2 + -0x2f) {
              return (uint)(*piVar1 < iVar2 + -0x30);
            }
          }
        }
      }
    }
  }
  return -1;
}

