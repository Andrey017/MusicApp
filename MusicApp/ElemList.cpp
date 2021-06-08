#include "ElemList.h"

void ElemList::CreateXML(array<ElemList^>^ elemList, int maxId)
{
    XmlDocument^ doc = gcnew XmlDocument();

    XmlDeclaration^ xmlDeclaration = doc->CreateXmlDeclaration("1.0", "UTF-8", nullptr);
    XmlElement^ root = doc->DocumentElement;
    doc->InsertBefore(xmlDeclaration, root);

    //создаем главный элемент
    XmlElement^ blocks = doc->CreateElement("blocks");
    doc->AppendChild(blocks);

    //цикл для создания блоков
    for (int l = 0; l < maxId; l++) {
        XmlElement^ block = doc->CreateElement("block");
        blocks->AppendChild(block);
        XmlAttribute^ block_id = doc->CreateAttribute("id");
        block->Attributes->Append(block_id);
        XmlText^ blockIdText = doc->CreateTextNode((l).ToString());
        block_id->AppendChild(blockIdText);

        //цикл для создания струн
        for (int i = 0; i < 6; i++) {
            XmlElement^ string = doc->CreateElement("string");
            block->AppendChild(string);
            XmlAttribute^ num = doc->CreateAttribute("num");
            string->Attributes->Append(num);
            XmlText^ stringNumText = doc->CreateTextNode((i).ToString());
            num->AppendChild(stringNumText);

            //цикл для создания элементов
            for (int j = 0; j < 4; j++) {
                XmlElement^ element = doc->CreateElement("element");
                string->AppendChild(element);
                XmlAttribute^ el_id = doc->CreateAttribute("el_id");
                element->Attributes->Append(el_id);
                XmlText^ el_id_text = doc->CreateTextNode((j).ToString());
                el_id->AppendChild(el_id_text);

                int k = j + i * 4 + l * 24;

                XmlElement^ value = doc->CreateElement("value");
                element->AppendChild(value);
                /*if (elemList[k]->value != "") {
                    XmlText^ valueText = doc->CreateTextNode(elemList[k]->value);
                    value->AppendChild(valueText);
                }
                else {
                    XmlText^ valueText = doc->CreateTextNode("-");
                    value->AppendChild(valueText);
                }*/
                XmlText^ valueText = doc->CreateTextNode(elemList[k]->value);
                value->AppendChild(valueText);

                XmlElement^ effect = doc->CreateElement("effect");
                element->AppendChild(effect);
                /*if (elemList[k]->effect != "") {
                    XmlText^ effectText = doc->CreateTextNode(elemList[k]->effect);
                    element->AppendChild(effectText);
                }
                else {
                    XmlText^ effectText = doc->CreateTextNode("-");
                    element->AppendChild(effectText);
                }*/
                XmlText^ effectText = doc->CreateTextNode(elemList[k]->effect);
                effect->AppendChild(effectText);
            }
        }
    }
    doc->Save("./document.xml");
}
