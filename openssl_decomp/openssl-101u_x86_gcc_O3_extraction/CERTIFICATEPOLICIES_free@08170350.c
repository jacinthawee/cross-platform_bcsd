
void CERTIFICATEPOLICIES_free(CERTIFICATEPOLICIES *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)CERTIFICATEPOLICIES_it);
  return;
}
