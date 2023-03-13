
void EC_GROUP_set_asn1_flag(EC_GROUP *group,int flag)

{
  *(int *)(group + 0x34) = flag;
  return;
}

