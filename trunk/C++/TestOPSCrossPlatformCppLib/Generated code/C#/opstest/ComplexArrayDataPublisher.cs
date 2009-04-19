
using OPS;
namespace opstest
{
    public class ComplexArrayDataPublisher 
        : Publisher 
    {


        public ComplexArrayDataPublisher(Topic t)
            :base(t)
        {
            
            setObjectHelper(new ComplexArrayDataHelper());

        }
        public void Write(ComplexArrayData o) 
        {
            base.Write(o);
        }


    }
}