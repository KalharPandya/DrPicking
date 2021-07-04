Peer PEsp;
json DRdata;

void pressedR1();
class DrPicking
{
    public:
    button *r1;
    int send_value=1;
    DrPicking(button *r1){
        this->r1=r1;
        attachAll();
        storeObject();
    }
    void attachAll()
    {
        r1->attachPress(pressedR1);
    }
    void d_pressedR1(){
        if(send_value==0){
            send_value=1;
        }
        else if(send_value==1)
        {
            send_value=0;
        }
        sendSingleData("Command",send_value);

    }
    
    void sendSingleData(String name,int value)
    {
        DRdata.clear();
        DRdata.addUnit(name,value);
        DRdata.addUnit("type","DRpick");
        
        PEsp.send(DRdata);
        Serial.println("data" + String(DRdata.getString()));
        DRdata.clear();
    }
    void storeObject();
};

DrPicking *DrPickingObject;

void DrPicking::storeObject()
{
    DrPickingObject = this;
}

void pressedR1(){
    DrPickingObject->d_pressedR1();
}

