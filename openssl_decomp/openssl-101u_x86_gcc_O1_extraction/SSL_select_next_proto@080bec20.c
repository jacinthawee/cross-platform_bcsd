
int SSL_select_next_proto
              (uchar **out,uchar *outlen,uchar *in,uint inlen,uchar *client,uint client_len)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint local_2c;
  uint local_24;
  
  local_24 = 0;
  if (inlen != 0) {
    do {
      if (client_len == 0) {
        local_2c = (uint)in[local_24];
      }
      else {
        uVar4 = 0;
        bVar1 = in[local_24];
        local_2c = (uint)bVar1;
        do {
          bVar2 = client[uVar4];
          if (bVar2 == bVar1) {
            iVar3 = memcmp(in + local_24 + 1,client + uVar4 + 1,local_2c);
            if (iVar3 == 0) {
              iVar3 = 1;
              client = in + local_24;
              goto LAB_080becb7;
            }
          }
          uVar4 = uVar4 + 1 + (uint)bVar2;
        } while (uVar4 < client_len);
      }
      local_24 = local_24 + 1 + local_2c;
    } while (local_24 < inlen);
  }
  iVar3 = 2;
LAB_080becb7:
  *out = client + 1;
  *outlen = *client;
  return iVar3;
}

