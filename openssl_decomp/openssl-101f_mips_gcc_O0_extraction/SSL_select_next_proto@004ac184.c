
int SSL_select_next_proto
              (uchar **out,uchar *outlen,uchar *in,uint inlen,uchar *client,uint client_len)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (inlen == 0) {
    iVar2 = 2;
  }
  else {
    uVar3 = 0;
    do {
      if (client_len == 0) {
        uVar5 = (uint)in[uVar3];
      }
      else {
        uVar4 = 0;
        uVar5 = (uint)in[uVar3];
        do {
          bVar1 = client[uVar4];
          if (bVar1 == uVar5) {
            iVar2 = (*(code *)PTR_memcmp_006aabd8)(in + uVar3 + 1,client + uVar4 + 1,uVar5);
            if (iVar2 == 0) {
              iVar2 = 1;
              client = in + uVar3;
              goto LAB_004ac244;
            }
          }
          uVar4 = uVar4 + bVar1 + 1;
        } while (uVar4 < client_len);
      }
      uVar3 = uVar3 + uVar5 + 1;
    } while (uVar3 < inlen);
    iVar2 = 2;
  }
LAB_004ac244:
  *out = client + 1;
  *outlen = *client;
  return iVar2;
}

