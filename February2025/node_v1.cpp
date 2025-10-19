#include <SOP/SOP_Node.h>

class SOP_MyNode : public SOP_Node {
public:
    static OP_Node* myConstructor(OP_Network *net, const char *name, OP_Operator *op) {
        return new SOP_MyNode(net, name, op);   //create only on heap
    }

protected:
    SOP_MyNode(OP_Network *net, const char *name, OP_Operator *op) : SOP_Node(net, name, op) {}

    virtual OP_ERROR cookMySop(OP_Context &context) override {
        // Get geometry object
        gdp->clearAndDestroy();
        
        // Add a single point at (0,0,0)
        gdp->appendPoint()->getPos() = UT_Vector3(0, 0, 0);
        return error();
    }
};

// Register the node
void newSopOperator(OP_OperatorTable *table) {                                  // Min/max inputs
    table->addOperator(new OP_Operator("my_sop", "My SOP", SOP_MyNode::myConstructor, 0, 0));
}

